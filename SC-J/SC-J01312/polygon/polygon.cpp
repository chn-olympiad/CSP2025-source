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
int n,a[5005],dp[10005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+1;j<=10001;++j)
			ans=(ans+dp[j])%998244353;
		int tot=0;
		for(int j=10000-a[i]+1;j<=10001;++j)
			tot=(tot+dp[j])%998244353;
		dp[10001]+=tot,
		dp[10001]%=998244353;
		if(i==n)
			break;
		for(int j=10000;j>=a[i];--j)
			dp[j]=(dp[j]+dp[j-a[i]])%998244353;
	}
	cout<<ans;
	return 0;
}
/*
已对拍1120组数据，不AC我吃啊

此题每挂1分，我围着操场跑10圈

不是，我45min就AK了

-Believe_in_Dreams 2025.11.1 CSP-J游记
*/