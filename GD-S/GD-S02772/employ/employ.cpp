#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500+5,p=998244353;
int n,m;
char s[N];
int c[N];
int vis[N],pr[N],cnt[N];
ll ans=0;
void dfs(int x){
	if(x==n+1){
		int now=0,k=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') now++;
			else {
				if(c[pr[i]]<=now) now++;
				else k++;
			}
		}
		if(k>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			pr[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
/*
18:13
luogu id : point_fish 
只想随便写点什么因为我说过我要写了。 
不会了，看了半小时T4只会指数级。
虽然在看 T4 但是我 T2 只写了暴力 T3 随机过样例。
不过t1 100 能打noip吧。
高二老登已经又菜又摆还爱筹集了 
现在真的挺开心的，体艺节一直有人在陪我，反正有人在意我我就特别开心就是了。
好吧我确实有很多不太好的习惯吧，平时也无意识的就会去做这些事情，抱歉大家。 

唉唉唉语文太差写什么都像流水账，如果有机会一定好好学语文。

以前想过自己是为了什么，今天中午看到了：I am because you are。总是在回忆，因为忘不了那些人。 

noip就不写这些了，祝 wzr,cyh,lzyx,lsy进队吧 嗯还有学弟 但是都好强我说不过来了。 

能不能生涯上一次GD迷惑行为大赏呢 

哦如果同校看到了不要拿这个嘲笑我 qwq 
18：25
*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') cnt0++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt0++;
	}
	if(m==n){
		if(cnt0>0) cout<<0;
		ans=1;
		for(int i=1;i<=n;i++)
			ans*=i,ans%=p;
		return 0;
	}
	if(n<=15){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
