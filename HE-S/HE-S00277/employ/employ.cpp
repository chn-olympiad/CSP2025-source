#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],p[N],cnt;
long long ans;
bool f=true;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (char c:s) cnt+=c-'0';s=" "+s;
	for (int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	if (cnt<m){cout<<0;return 0;}
	do{
		int cnt=0;
		for (int j=1;j<=n;j++){
			int i=p[j];
			if (cnt>=c[i]){++cnt;continue;}
			if (s[j]=='0') ++cnt;
		}
		if (n-cnt>=m) ++ans;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
