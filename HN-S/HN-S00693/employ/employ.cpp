#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1145;
int n,m,ans;
string s;
int c[maxn];
int res[maxn];
bool f[maxn];
void dfss(int dep){
	if(dep==n+1){
		int sum=0;
		for(int i=1;i<=n;i++)
			if(!(s[i-1]-'0')||c[res[i]]<=sum)
				sum++;
		if(n-sum>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!f[i]){
			res[dep]=i;
			f[i]=true;
			dfss(dep+1);
			f[i]=false;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfss(1);
cout<<ans<<'\n';
	return 0;
}
