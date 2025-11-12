#include<bits/stdc++.h>
#define ll long long
using namespace std;
//注意返回值 Ren5Jie4Di4Ling5%
const int N=505,mod=998244353;
ll jc[N];
int a[N];
bool vis[N];
int per[N];
ll n,m;string s;
ll ans=0;
void dfs(int d){
	if(d==n+1){
		//模拟
		int cnt=0;
		int lea=0;
		for(int i=1;i<=n;i++){
			if(lea>=a[per[i]]){
				lea++;continue;
			}
			if(s[i-1]=='0'){
				lea++;continue;
			}
			cnt++;
		}
		if(cnt>=m)ans++,ans%=mod;
//		for(int i=1;i<=n;i++){
//			cout<<per[i]<<" "<<a[per[i]]<<endl;
//		}cout<<cnt<<endl;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		per[d]=i;
		dfs(d+1);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
//	system("FC employ3.ANS employ3.OUT");
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<N;i++){
		jc[i]=(jc[i-1]*i)%mod;
	}
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>11){
		cout<<0;return 0;
	}
	else dfs(1);
	cout<<ans<<endl;//8pts,小于去年。 
	return 0;
}
/*
AFO
18:18 可能有点思路，但是肯定写不了。
先调暴力，我暴力都没过样例。
原来是字符串索引没 -1。 

如果大样例不弱则100+80+100+8,没对拍。 
我觉得大样例不强。 
*/
