#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[505],p[505],v[505],len;
int f=0,sum;
void dfs(int x,int d){
	if(n-d<m){
		return;
	}
	if(x==n+1){
		/*int cnt=0,k=0;
		for(int i=1;i<=n;i++){
			if(cnt>=p[i]||s[i]=='0'){
				cnt++;
			}
			else{
				k++;
				if(k>=m){
					sum++;
					sum%=mod;
					return;
				}
				if(k+n-i<m){
					return;
				}
			}		
		}
		if(k>=m){
			sum++;
			sum%=mod;
		}
		return;*/
		sum=(sum+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			p[++len]=a[i];
			v[i]=1;
			if(a[i]<=d||s[x]=='0'){
				d++;
			}
			dfs(x+1,d);
			v[i]=0;
			len--;
			if(a[i]<=d||s[x]=='0'){
				d--;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    if(s[i]=='0'){
			f++;
		}
	}
	if(m==n){
		if(f){
			cout<<0;
			return 0;
		}
	}
	dfs(1,0);
	cout<<sum;
	return 0;
}
