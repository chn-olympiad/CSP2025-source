#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int ans;
int xx;
bool vis=true;
signed main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==0){
			vis=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			xx++;
		}
	}//cout<<xx<<endl;
	sort(c+1,c+n+1);
	if(n==m){
		ans=1;
		for(int i=1;i<=n;i++){
			int t=1;
			if(c[i]!=0&&c[i]==c[i+1]&&c[i]>i){
				t++;
			}else{
				ans*=t;
				ans%=mod;
			}
		}
		cout<<ans;
		return 0;
	}	
	
	for(int i=1;i<=n;i++){
		if(c[i]!=0&&c[i]>=i){
			ans++;
		}ans%=mod;
	}
	cout<<ans%mod;
	return 0;

}
