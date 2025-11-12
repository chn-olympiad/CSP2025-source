#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+5;
ll n,ans,l[5];
ll a[M][5],b[M],cnt;
ll op[M];
void clean(){
	for(int i=1;i<=n;i++){
		op[i]=0;
	}
	ans=l[0]=l[1]=l[2]=cnt=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			a[i][0]=x,a[i][1]=y,a[i][2]=z;
			if(x>=y&&x>=z){
				l[0]++,ans+=x;
				op[i]=0;
			}else if(y>=z){
				l[1]++,ans+=y;
				op[i]=1;
			}else{
				l[2]++,ans+=z;
				op[i]=2;
			}
		}
		if(l[0]<=n/2&&l[1]<=n/2&&l[2]<=n/2){
			cout<<ans<<"\n";
		}else{
			if(l[0]>=n/2){
				for(int i=1;i<=n;i++){
					if(op[i]==0){
						b[++cnt]=a[i][0]-max(a[i][1],a[i][2]);
					}
				}
			}else if(l[1]>=n/2){
				for(int i=1;i<=n;i++){
					if(op[i]==1){
						b[++cnt]=a[i][1]-max(a[i][0],a[i][2]);
					}
				}
			}else{
				for(int i=1;i<=n;i++){
					if(op[i]==2){
						b[++cnt]=a[i][2]-max(a[i][1],a[i][0]);
					}
				}
			}
			sort(b+1,b+1+cnt);
			for(int i=1;i<=cnt-n/2;i++)ans-=b[i];
			cout<<ans<<"\n";
		}
		clean();
	}
}
