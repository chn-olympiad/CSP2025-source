#include<bits/stdc++.h>
using namespace std;
int n,m,t;
struct zzy{
	int a,b,c,ma,id,ne,nid,la,lid;
}z[100005];
bool zzzy(zzy z,zzy y){
	return z.ma>y.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>z[i].a>>z[i].b>>z[i].c;
			if(z[i].a>=z[i].b&&z[i].a>=z[i].c){
				z[i].ma=z[i].a;
				z[i].id=1;
				if(z[i].b>z[i].c) {
					z[i].ne=z[i].b;
					z[i].nid=2;
					z[i].la=z[i].c;
					z[i].lid=3;
				}
				else{
					z[i].ne=z[i].c;
					z[i].nid=3;
					z[i].la=z[i].b;
					z[i].lid=2;
				}
			}
			else if(z[i].b>z[i].a&&z[i].b>z[i].c){
				z[i].ma=z[i].b;
				z[i].id=2;
				if(z[i].a>z[i].c) {
					z[i].ne=z[i].a;
					z[i].nid=1;
					z[i].la=z[i].c;
					z[i].lid=3;
				}
				else{
					z[i].ne=z[i].c;
					z[i].nid=3;
					z[i].la=z[i].a;
					z[i].lid=1;
				}
			}
			else{
				z[i].ma=z[i].c;
				z[i].id=3;
				if(z[i].a>z[i].b) {
					z[i].ne=z[i].a;
					z[i].nid=1;
					z[i].la=z[i].b;
					z[i].lid=2;
				}
				else{
					z[i].ne=z[i].b;
					z[i].nid=2;
					z[i].la=z[i].a;
					z[i].lid=1;
				}
			}
		}
		sort(z+1,z+n+1,zzzy);
		int zy[4]={0};
		int ans=0;
		for(int i=1;i<=n;i++){
			if(zy[z[i].id]*2>=n){
				if(zy[z[i].nid]>=n/2){
					ans+=z[i].la;
					zy[z[i].lid]++;
				}
				else {
					ans+=z[i].ne;
					zy[z[i].nid]++;
				}
			}
			else{
				ans+=z[i].ma;
				zy[z[i].id]++;
			}
		}
		//for(int i=1;i<=n;i++) cout<<z[i].ma<<' '; 
		cout<<ans<<'\n';
	}
	return 0;
} 
