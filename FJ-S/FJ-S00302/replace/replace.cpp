#include <bits/stdc++.h>
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define endl '\n'
#define mem(a,v) memset(a,v,sizeof(a))
#define pll pair<long long,long long>
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define mkp make_pair
//#define int long long
using namespace std;
using ll=long long;
using lld=long double;
const int N=2e5+10,M=5e6+10;
int n,q,ans,L1;
string s[N][3],t[N][3];
signed main(){
	FILE("replace");
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2],L1+=s[i][1].size()*2;
	if(q*L1>2e6){
		for(int i=1;i<=q;i++)cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=q;i++){
		ans=0,cin>>t[i][1]>>t[i][2];
		for(int j=1;j<=n;j++){
			for(int p=t[i][1].find(s[j][1],0);p>=0;p=t[i][1].find(s[j][1],p+1)){
				string t2=t[i][1];
				for(int k=0;k<s[j][2].size();k++)
					t2[k+p]=s[j][2][k];
				if(t2==t[i][2])ans++;
//				cerr<<j<<' '<<p<<' '<<t2<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

