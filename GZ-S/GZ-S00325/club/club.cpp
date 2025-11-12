//GZ-S00325 贵阳市第一中学 王梓竣 
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nod{
	int num[5];
	int mi,m1,m2;
}l[100005];
int a,b,c,n,m,ans,tot,T;
int slt[4][100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		memset(slt,0,sizeof(slt));
		memset(l,0,sizeof(l));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>l[i].num[j];
				if(l[i].num[j]>l[i].m1){
					l[i].m2=l[i].m1;
					l[i].m1=l[i].num[j];
					l[i].mi=j;
				}else if(l[i].num[j]>l[i].m2){
					l[i].m2=l[i].num[j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			slt[l[i].mi][++slt[l[i].mi][0]]=l[i].m1-l[i].m2;
			ans+=l[i].m1;
		}
		for(int j=1;j<=3;j++){
			if(slt[j][0]>n/2){
				sort(slt[j]+1,slt[j]+1+slt[j][0]);
				for(int i=1;i<=slt[j][0]-n/2;i++){
					ans-=slt[j][i];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
