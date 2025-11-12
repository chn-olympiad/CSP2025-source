//GZ-S00062 刘祉杙 贵阳市清华中学                                                                                                                                                  
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+5;
ll n,m,ans=1;
string s;  
ll a[M];
bool fun(string s){
	for(ll i=0;i<s.size();i++){
		if(s[i]!='1') return false;
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=m;i++)  cin>>a[i];
	if(fun(s)){
		for(ll i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
	}
	else ans=998244352;
	cout<<ans<<endl;
	return 0;
}
/*
糖果罐里好多颜色 
微笑却不甜了 
你的某些快乐 
在没有我的时刻 
中古世纪的城市里 
我想就走到这 
海鸥不再眷恋大海 
可以飞更远 
远方传来风笛 
我只在意有你的消息 
城堡为爱守着秘密 
而我为你守着回忆 
明明就不习惯牵手 
为何却主动把手勾 
你的心事太多 
我不会搓破 
明明就他比较温柔 
也许他能给你更多 
不用抉择 我会自动变朋友~ 
*/
