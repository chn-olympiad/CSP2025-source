#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
int n,m;string s;
int c[1000005];
int ans,c1[1000005];
bool pd(){
	int now=0,cnt=0;
	for(int i=0;i<n;++i){
		if(now<=c[i+1])++cnt;
		else ++now;
		now+=s[c1[i+1]]-'0';
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i)c1[i]=i-1;
	int d=0;do{
		ans+=pd();
		++d;
	}while(next_permutation(c1+1,c1+n+1));
	cout<<ans<<'\n';
	return 0;
}