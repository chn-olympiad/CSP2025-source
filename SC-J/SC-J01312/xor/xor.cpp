#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(ll x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
const int N=5e5+5,M=1e7+5;
int n,k,a[N],dp[N];
int t[M];
void pre(int p,int l,int r){
	t[p]=-1e9;
	if(l==r)
		return;
	int mid=l+r>>1;
	pre(p<<1,l,mid);
	pre(p<<1|1,mid+1,r);
}
void add(int p,int l,int r,int x,int c){
	if(l==r){
		t[p]=max(t[p],c);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		add(p<<1,l,mid,x,c);
	else
		add(p<<1|1,mid+1,r,x,c);
	t[p]=max(t[p<<1],t[p<<1|1]);
}
int ask(int p,int l,int r,int x){
	if(l==r)
		return t[p];
	int mid=l+r>>1;
	if(x<=mid)
		return ask(p<<1,l,mid,x);
	return ask(p<<1|1,mid+1,r,x);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i)
		a[i]=a[i-1]^read();
	pre(1,0,2097153);
	add(1,0,2097153,0,0);
	for(int i=1;i<=n;++i){
		dp[i]=max(dp[i-1],ask(1,0,2097153,a[i]^k)+1);
		add(1,0,2097153,a[i],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
/*
对拍了3000组数据
这不稳？
极限数据0.3秒
内存1e7*4/1048576=38M
效率杠杠的
这不AC我吃啊

此题每挂1分，我围着操场跑10圈



我踏着坎坷的路走来，
走向山顶。

站在制高点，
回首望，
路是一道风景，
路是一片回忆。
回首望，
有人遥望彼岸，
有人低头前行。

站在制高点，
抬头看，
苍穹万丈高，
云雾腿脚边。
抬头看，
太阳照亮青空，
太阳温暖心空。

我要往前走了。
顶峰前的悬崖，
既是归宿，
亦是征途。

我向你们招手，
目光里充斥着坚定。
像是出发前的招手，
亦是永别前的誓言。
*/