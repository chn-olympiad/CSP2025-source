#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int num,id;
	bool operator < (const Node a)const{
		return num>a.num;
	}
}a[N],b[N],c[N];
int t,n,ans,suma,sumb,sumc;
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=suma=sumb=sumc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].id=b[i].id=c[i].id=i;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			if(a[i].num>=b[i].num&&b[i].num>=c[i].num){
				if(!vis[a[i].id]&&suma<n/2){
					ans+=a[i].num;
					suma++;
				}
				if(!vis[b[i].id]&&sumb<n/2){
					ans+=b[i].num;
					sumb++;
				}
				if(!vis[c[i].id]&&sumc<n/2){
					ans+=c[i].num;
					sumc++;
				}
			}
			else if(b[i].num>=c[i].num&&c[i].num>=a[i].num){
				if(!vis[b[i].id]&&sumb<n/2){
					ans+=b[i].num;
					sumb++;
				}
				if(!vis[c[i].id]&&sumc<n/2){
					ans+=c[i].num;
					sumc++;
				}
				if(!vis[a[i].id]&&suma<n/2){
					ans+=a[i].num;
					suma++;
				}
			}
			else if(c[i].num>=a[i].num&&a[i].num>=b[i].num){
				if(!vis[c[i].id]&&sumc<n/2){
					ans+=c[i].num;
					sumc++;
				}
				if(!vis[a[i].id]&&suma<n/2){
					ans+=a[i].num;
					suma++;
				}
				if(!vis[b[i].id]&&sumb<n/2){
					ans+=b[i].num;
					sumb++;
				}
			}
			else if(a[i].num>=c[i].num&&c[i].num>=b[i].num){
				if(!vis[a[i].id]&&suma<n/2){
					ans+=a[i].num;
					suma++;
				}
				if(!vis[c[i].id]&&sumc<n/2){
					ans+=c[i].num;
					sumc++;
				}
				if(!vis[b[i].id]&&sumb<n/2){
					ans+=b[i].num;
					sumb++;
				}
			}
			else if(b[i].num>=a[i].num&&c[i].num>=c[i].num){
				if(!vis[b[i].id]&&sumb<n/2){
					ans+=b[i].num;
					sumb++;
				}
				if(!vis[a[i].id]&&suma<n/2){
					ans+=a[i].num;
					suma++;
				}
				if(!vis[c[i].id]&&sumc<n/2){
					ans+=c[i].num;
					sumc++;
				}
			}
			else{
				if(!vis[c[i].id]&&sumc<n/2){
					ans+=c[i].num;
					sumc++;
				}
				if(!vis[b[i].id]&&sumb<n/2){
					ans+=b[i].num;
					sumb++;
				}
				if(!vis[a[i].id]&&suma<n/2){
					ans+=a[i].num;
					suma++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
