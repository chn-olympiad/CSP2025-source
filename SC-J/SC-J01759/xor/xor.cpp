#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct node{
	ll x,y;
}t[1000005];
ll n,k,a[1000005],zh[5005][5005],cnt,ans,mx,mp1,mp0;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1; ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0',ch=getchar();}
	return x*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		zh[i][i]=a[i]=read();
		mx=max(mx,a[i]);
		if(a[i]==1) mp1++;
		if(a[i]==0) mp0++;
	}
	if(mx==1){
		if(k==1) cout<<mp1;
		else{
			ll sum=1,s=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]&&a[i]) sum++;
				else{
					s+=sum/2;
					sum=1;
				}
			}
			cout<<s+mp0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			zh[i][j]=zh[i][j-1]^a[j];
			if(zh[i][j]==k)
				t[++cnt].x=i,t[cnt].y=j;
		}
	}
	ll ti=0;
	for(int i=1;i<=n;i++){
		if(ti<t[i].x){
			ans++;
			ti=t[i].y;
		}
	}
	cout<<ans;
	return 0;
}