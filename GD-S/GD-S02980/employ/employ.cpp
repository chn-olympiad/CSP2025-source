#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll mod=998244353;
int n,m;
string s;
ll t[N],p[N],c[N];
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		p[i]=i;
		if(s[i-1]=='0')
			t[i]=0;
		else
			t[i]=1;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||t[i]==0)
				cnt++;
		}
		if(n-cnt>=m)
			ans=(ans+1)%mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl; 
	return 0;
} 
