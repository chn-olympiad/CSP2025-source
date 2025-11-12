#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=5e5+10;
LL a[N],n,k,ans=0;
LL dp[N];
LL read(){
	LL f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
bool check(LL i,LL j){
	for(LL l=i;l>j;l--){
		LL x=a[i],y=a[l-1];
		x^=y;
		if(x==k) return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;i++)
		a[i]=a[i-1]^read();
	for(LL i=1;i<=n;i++)
		for(LL j=0;j<i;j++)
			dp[i]=max(dp[i],dp[j]+check(i,j));
	for(LL i=1;i<=n;i++)
		ans=max(dp[i],ans);
	cout<<ans<<endl;
	return 0;
}
