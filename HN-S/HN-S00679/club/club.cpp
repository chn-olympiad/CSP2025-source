#include<bits/stdc++.h>
using namespace std;
struct init{
	int num,per,s;
};
bool cmp(init a,init b){
	if(a.num>b.num){
		return 1; 
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	
	for(int ppp=1;ppp<=t;ppp++){
		
		
		int n;
		cin>>n;
		init a[10001]={};
		int ans=0;
		int w=0,ww=0,www=0;
		int l=n/2;
		bool flag[100001]={};
		int c=1;
		for(int i=1;i<=n;i++){
			cin>>a[c].num>>a[c+1].num>>a[c+2].num;
			a[c].s=1,a[c+1].s=2,a[c+2].s=3;
			a[c].per=i,a[c+1].per=i,a[c+2].per=i;
			c+=3;
		}
		
		
		sort(a+1,a+3*n+1,cmp);
//		for(int i=1;i<=3*n;i++){
//			cout<<i <<"  num: "<<a[i].num<<"   d "<<a[i].per<<"   s "<<a[i].s<<endl;
//		}
//		
		for(int i=1;i<=3*n;i++){
//			cout<<"i: "<<i<<endl;
			int br=1;
			for(int j=1;j<=n;j++){
//				cout<<flag[j]<<' ';
				if(!flag[j]){
					br=0;
				}
			}
			if(br==1){
				break;
			}
//			cout<<endl;
//			cout<<"a[i].per: "<<a[i].per<<" a[i].s:"<<a[i].s<<endl;
//			cout<<"w: "<<w<<" ww: "<<ww<<" www: "<<www<<endl;
			if(flag[a[i].per]==0){
				flag[a[i].per]=1;
				
					if(a[i].s==1&&w<l){
						w++;
						ans+=a[i].num;
//						cout<<"ans:"<<ans<<endl;
					}else if(a[i].s==2&&ww<l){
						ww++;
						ans+=a[i].num;
//						cout<<"ans:"<<ans<<endl;
					}else if(a[i].s==3&&www<l){
						www++;
						ans+=a[i].num;
//						cout<<"ans:"<<ans<<endl;
					}
				}
//			cout<<"w: "<<w<<" ww: "<<ww<<" www: "<<www<<endl;
			for(int j=1;j<=n;j++){
//				cout<<flag[j]<<' ';
			}
//			cout<<endl;
			
			}
		
		cout<<ans<<endl;
	}
	return 0;
}
