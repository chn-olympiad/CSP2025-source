#include<iostream>
#include<unordered_map>
#include<stdlib.h>
using namespace std;
const __int128 mod=1e15+37,base=1145141;
long long n,q;
__int128 dif[200001],ran[26];
string s[200001][2];
unordered_map<long long,long long>mp;
__int128 quickpow(__int128 n,__int128 k)
{
	__int128 ans=1ll;
	while(k!=0)
	{
		if(k&1)
		  ans=ans*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return ans;
}
string t[2];
void work()
{
	cin>>t[0]>>t[1];
	__int128 has=0;
	for(int z=0;z<t[0].size();z++)
	  has=((__int128)has*base%mod+((__int128)(-ran[t[0][z]-'a']+ran[t[1][z]-'a'])+mod)%mod)%mod;
	__int128 cnt=1,recl=quickpow(base,mod-2);
	long long ans=0;
	for(int z=t[0].size()-1;z>-1;z--)
	{
		ans+=mp[(__int128)has*(__int128)cnt%mod];
		cnt=(__int128)cnt*(__int128)recl%mod;
		if(t[0][z]!=t[1][z])
		  break;
	}
	cout<<ans<<endl;
}
__int128 exrand()
{
	return ((__int128)rand()<<15)+rand()%base;
}
int main()
{
//	if(system("fc replace.out replace3.ans")){}
//	freopen("replace3.in","r",stdin);
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	srand((unsigned)time(NULL));
	for(int z=0;z<26;z++)
	  ran[z]=exrand();
	cin>>n>>q;
	for(int z=1;z<=n;z++)
	{
		for(int y=0;y<2;y++)
		  cin>>s[z][y];
		for(int y=0;y<s[z][0].size();y++)
		  dif[z]=((__int128)dif[z]*base%mod+((__int128)(-ran[s[z][0][y]-'a']+ran[s[z][1][y]-'a'])+mod)%mod)%mod;
		mp[dif[z]]++;
	}
	for(int z=1;z<=q;z++)
	  work();
	return 0;
}/*
为什么哈希冲突这么严重。。。
看大样例这么多0，这题该和随机化有点关系吧。。。
感觉前5点暴力部分应该不至于冲突了，性质A不知道能不能过
反正是没有100pts了
应该保底有25吧 
*/
