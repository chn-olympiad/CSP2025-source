#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505+12;
const ll mod=998244353;
int n,m;
char _;
bool diff[N];
int c[N];
int p[N]; 
ll ans=0;
bool vis[N];
void dfs(int now){
	if(now==n+1){
		int dead=0;
		for(int i=1;i<=n;i++){
			if(diff[i]==0){
//				cout<<"!";
				dead++;
			}else{
				if(c[p[i]]<=dead){
//					cout<<"("<<c[p[i]]<<")["<<dead<<"]";
					dead++;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<' ';
//		}
//		cout<<" dead="<<dead<<endl;
		if(n-dead>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	bool flagA=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>_;
		diff[i]=_-'0';
		if(diff[i]==0)flagA=0;
	}
//	for(int i=1;i<=n;i++){
//		cout<<diff[i]<<endl;
//	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	if(n<=10){
		dfs(1);
		cout<<ans%mod;
		return 0;
	}
	if(m==n){
		if(!flagA){
			cout<<"0";return 0;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
} 
