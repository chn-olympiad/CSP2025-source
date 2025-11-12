#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,sid,ma,sma,cz,ip;
}a[100010];
int vis[5];
bool cmp(node x,node y){
	return x.cz>y.cz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		long long int n,m,ans=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			int x,y,z,sma,ma,id,sid;
			cin>>x>>y>>z;
			if(x>y){
				if(x>z){
					if(y>z){
						sma=y;
						sid=2;
					}
					else{
						sma=z;
						sid=3;
					}
					ma=x;
					id=1;
				}
				else{
					ma=z;
					id=3;
					sma=x;
					sid=1;
				}
			}
			else{
				if(y>z){
					if(x>z){
						sma=x;
						sid=1;
					}
					else{
						sma=z;
						sid=3;
					}
					ma=y;
					id=2;
				}
				else{
					ma=z;
					id=3;
					sma=y;
					sid=2;
				}
			}
			a[i].ip=i;
			a[i].id=id;
			a[i].sid=sid;
			a[i].ma=ma;
			a[i].sma=sma;
			a[i].cz=ma-sma;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(vis[a[i].id]<m){
				ans+=a[i].ma;
				vis[a[i].id]+=1;
			}
			else{
				ans+=a[i].sma;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
