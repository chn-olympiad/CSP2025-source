#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
struct clu{
	int data,number;
}a[100001],b[100001],c[100001];
bool cmp(clu x,clu y){
	return x.data>y.data;
}
bool cmp2(clu x,clu y){
	return x.data<y.data;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.txt","w",stdout); 
	int k;
	cin>>k;
	while(k--){
		int ans=0;
		int max1=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			a[i].number=i,b[i].number=i,c[i].number=i;
			cin>>a[i].data>>b[i].data>>c[i].data;
			b[i].data-=a[i].data;
			c[i].data-=a[i].data;
			max1+=a[i].data; 
		}
		sort(c,c+n,cmp);
		sort(b,b+n,cmp);
		sort(a,a+n,cmp2);
//		cout<<"max1:"<<max1<<endl;
//		cout<<"c:\n";
//		for(int i=0;i<n;i++)cout<<c[i].data<<" "<<c[i].number<<endl;
//		cout<<"b:\n";
//		for(int i=0;i<n;i++)cout<<b[i].data<<" "<<b[i].number<<endl;
		int lim=n/2;
		for(int a1=lim;a1>=0;a1--){
			int i=0,j=0,max2=max1,n1=0,n2=0;
			bool num[100001]={false};
			while(n1+n2<n-a1){
				if(num[b[i].number]==true){
					i++;
					continue;
				}
				if(num[c[j].number]==true){
					j++;
					continue;
				}
				if(n2==lim){
					max2+=b[i++].data;
					n1++;
					continue;
				}
				if(n1==lim){
					max2+=c[j++].data;
					n2++;
					continue;
				}
				if(b[i].number==c[j].number){
					if(cmp(b[i],c[j])){
						n1++;
						max2+=b[i].data;
					}else{
						n2++;
						max2+=c[j].data;
					}
					num[b[i].number]=true;
					i++,j++;
				}else{
					if(cmp(b[i],c[j])){
						num[b[i].number]=true;
						max2+=b[i++].data;
						n1++;
					}else{
						num[c[j].number]=true;
						n2++;
						max2+=c[j++].data;
					}
				}
			}
//			cout<<a1<<": "<<max2<<endl;
			ans=max(ans,max2); 
		}
		cout<<ans<<endl;
	}
}
