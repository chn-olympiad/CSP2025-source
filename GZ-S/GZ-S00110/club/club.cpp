//GZ-S00110 周洵羽 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
int t,n,lena,lenb,lenc,ans;
struct node{
	int a,b,c;
};
node d[100005],a_1[100005],b_1[100005],c_1[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].a>=d[i].b && d[i].a>=d[i].c){
				lena++;
				a_1[lena]=d[i];
				//ans+=d[i].a;
			}
			else if(d[i].b>=d[i].a && d[i].b>=d[i].c){
				lenb++;
				b_1[lenb]=d[i];
				//ans+=d[i].b;
			}
			else if(d[i].c>=d[i].b && d[i].c>=d[i].a){
				lenc++;
				c_1[lenc]=d[i];
				//ans+=d[i].c;
			}
			ans+=max(d[i].a,max(d[i].b,d[i].c));
		}
		int j=lena;
		while(j>(n/2)){//a多了 
			int pos,minzhi=INT_MAX;
			for(int i=1;i<=lena;i++){//找差最小 
				int aa=abs(a_1[i].a-a_1[i].b) , bb=abs(a_1[i].a-a_1[i].c);//aa=a-b,bb=a-c; 
				if(aa<=minzhi || bb<=minzhi){//当前有更小 
					minzhi=min(aa,bb);
					pos=i;
				}
			}
			j--;
			ans-=minzhi;//离开降低 
			a_1[pos].a=INT_MAX;//请出去 
		}
		j=lenb;
		while(j>(n/2)){//b多了 
			int pos,minzhi=INT_MAX;
			for(int i=1;i<=lenb;i++){//找差最小 
				int aa=abs(b_1[i].b-b_1[i].a) , bb=abs(b_1[i].b-b_1[i].c);//aa=b-a,bb=b-c; 
				if(aa<=minzhi || bb<=minzhi){//当前有更小 
					minzhi=min(aa,bb);
					pos=i;
				}
			}
			j--;
			ans-=minzhi;//离开降低 
			b_1[pos].b=INT_MAX;//请出去 
		}
		j=lenc; 
		while(j>(n/2)){//c多了 
			int pos,minzhi=INT_MAX;
			for(int i=1;i<=lenc;i++){//找差最小 
				int aa=abs(c_1[i].c-c_1[i].b) , bb=abs(c_1[i].c-c_1[i].a);//aa=c-b,bb=c-a; 
				if(aa<=minzhi || bb<=minzhi){//当前有更小 
					minzhi=min(aa,bb);
					pos=i;
				}
			}
			j--;
			ans-=minzhi;//离开降低 
			c_1[pos].c=INT_MAX;//请出去 
		}
		cout<<ans<<endl;
		ans=lena=lenb=lenc=0;
	}
	return 0;
}
