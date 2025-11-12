#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef unsigned long long ll;
const ll c=131;
const int N=2e5+7, M=5e6+7;
int n, q;
string s[N][2];
ll hash_s[N][2];
ll pre[M], base[M], Hash=0;
string t[2];
ll get(int l, int r){
	if(l>r) return 0ull;
	return pre[r]-pre[l-1]*base[r-l+1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	base[0]=1;
	for(int i=1;i<=5000000;i++)
		base[i]=base[i-1]*c;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++)
			hash_s[i][0]=hash_s[i][0]*c+1ull*s[i][0][j];
		for(int j=0;j<s[i][1].size();j++)
			hash_s[i][1]=hash_s[i][1]*c+1ull*s[i][1][j];
	}
	while(q--){
		cin>>t[0]>>t[1];
		Hash=0;
		for(int i=0;i<t[1].size();i++)
			Hash=Hash*c+1ull*t[1][i];
		pre[0]=1ull*t[0][0];
		for(int i=1;i<t[0].size();i++)
			pre[i]=pre[i-1]*c+1ull*t[0][i];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j+s[i][0].size()-1<t[0].size();j++)
				if(get(j, j+s[i][0].size()-1)==hash_s[i][0] && (j==0?0ull:pre[j-1]*base[t[0].size()-j])+hash_s[i][1]*base[t[0].size()-j-s[i][0].size()]+get(j+s[i][0].size(), t[0].size()-1)==Hash)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}