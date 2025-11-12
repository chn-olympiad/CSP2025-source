#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
const int N=5e5+5;
int n,k,ans;
int a[N],sum[N],cnt[N][21];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)sum[i]=a[i]^sum[i-1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++){
			if(a[i]&(1<<j))cnt[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++)cnt[i][j]+=cnt[i-1][j];
	}
	int last=0;
	for(int i=1;i<=n;i++){
		if(n>200005){
			bool f=1;
			for(int j=0;j<20;j++){
				if(k&(1<<j)){
					if(cnt[i][j]-cnt[last][j]==0)f=0;
				}
			}
			if(!f)continue;
		}
		for(int j=last;j<i;j++){
			if((sum[i]^sum[j])==k){
				ans++;
				last=i;
				break;
			}
		}
	}
	write(ans);
	return 0;
}
/*
妈妈
*/