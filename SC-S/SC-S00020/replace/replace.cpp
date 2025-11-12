#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
string s1[N],s2[N],s[N],ss[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!=s2[i][j]) s[i]+=s1[i][j],ss[i]+=s2[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		string t1,t2,t,tt;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]) t+=t1[j],tt+=t2[j];
		}
		for(int j=1;j<=n;j++){
			if(s[j]==t&&ss[j]==tt) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*


*/