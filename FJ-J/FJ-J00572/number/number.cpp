#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int n,a[maxn],tot;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1);
	if(!a[tot]){
		cout<<0;
		return 0;
	}
	for(int i=tot;i;i--) cout<<a[i];
}
/*
自扰—那个少年【续】
序： 
我感觉到了，那个少年并未离开，
他的执念太深了，他一直都在…
正文： 
你一直在看着我吗？还是你早已回来。 
不，或许我只是你的一念罢了。
你的愿景与我的愿景又有何差别呢？ 

我常常追忆过去，碎云般的思绪皆映着你的青春
我常常挽留现在，以终幕之舞牵引回你的记忆与情思
我常常恐惧未来，未来的你与我或许早已不是一路之人

若问命中赢否？
那个少年必当满怀热血的回答-赢！
现在呢？未来呢？我常常回答-赢？ 
*/ 

