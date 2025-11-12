#include<bits/stdc++.h>
using namespace std;
int n,m,len;
constexpr int mod1=998244353,mod2=1e9+7,base=26;
constexpr int N=2e5+5;
constexpr int L=5e6+5;
string s[N],s1,s2;
long long sha1[L],sha2[L];
long long tha1[L],tha2[L];
long long po1[L],po2[L],ans[N];
string t[N],t1,t2;
inline bool equa(int blt,int lt,int rt,int k)
{
	for(int i=lt,j=1;j<(int)s[k].size();++j,++i)if(t[blt][i]!=s[k][j])return false;
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,len;i<=n;++i){
		cin>>s1>>s2;len=s1.size();s[i]="#";
		for(int j=0;j<len;++j)s[i]+=s1[j],s[i]+=s2[j];
	}
	for(int i=1,len;i<=m;++i){
		cin>>t1>>t2;len=t1.size();t[i]="#";
		for(int j=0;j<len;++j)t[i]+=t1[j],t[i]+=t2[j];
	}
	for(int i=1,l,r;i<=m;++i){
		len=t[i].size();
		for(l=1;;l+=2)if(t[i][l]!=t[i][l+1])break;
		for(r=len-1;;r-=2)if(t[i][r]!=t[i][r-1])break;
		for(int k=1,len2;k<=n;++k){
			len2=s[k].size();
			if(len2>len||len2<r-l+1)continue;
			for(int lt=r-len2+1,rt=r-1;lt<=l&&rt<=len;++lt,++rt){
				if(lt<1)continue;
				if(equa(i,lt,rt,k)){++ans[i];break;}
			}
		}
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<'\n';
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
