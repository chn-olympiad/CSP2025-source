#include<bits/stdc++.h>
#define int long long
#define N (int)(5e5+5)
using namespace std;
int a[N],ans,n,k;
int Xor[N];
//int dp[N][N];
int bck[N];
int fro[N];
inline void read(int &num);
inline void solve();
inline void solve2();
inline int getval(int l,int r);
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
	while(T--){
		solve2();
	}
	return 0;
}
inline void read(int &num){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		f=(ch=='-')?-1:1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	num=x*f;
}
/*
inline void solve(){
	read(n);
	read(k);
	for(int i=1;i<=n;++i){
		read(a[i]);
		Xor[i]=Xor[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		dp[i][i]=getval(i,i);
	}
	for(int step=0;step<=n-1;++step){
		for(int l=1;l<=n-step;++l){
			int r=l+step;
			dp[l][r]=max(dp[l][r],getval(l,r));
			for(int k=l;k<r;++k){
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
				dp[l][r]=max(dp[l][r],getval(l,k)+getval(k+1,r));
			}
		}
	}
	printf("%lld\n",dp[1][n]);
}
*/
inline void solve2(){
	bool flag=true;
	read(n);
	read(k);
	for(int i=1;i<=n;++i){
		read(a[i]);
		if(a[i]>1)flag=false;
		Xor[i]=Xor[i-1]^a[i];
	}
	if(flag&&n>=(int)(1e4)){
		if(k>1){
			puts("0");
		}else{
			int ct_0=0,ct_1=0;
			for(int i=1;i<=n;++i){
				if(a[i]==0){
					++ct_0;
				}else if(a[i]==1){
					++ct_1;
				}
			}
			if(k==1){
				printf("%lld\n",ct_1);
			}else{
				printf("%lld\n",ct_0);
			}
		}
	}
	fro[1]=getval(1,1);
	for(int step=0;step<=n-1;++step){
		int r=1+step;
		for(int k=1;k<r;++k){
			fro[r]=max(fro[r],fro[k]+getval(k+1,r));
		}
	}
	bck[n]=getval(n,n);
	for(int step=0;step<=n-1;++step){
		int l=n-step;
		for(int k=n;k>l;--k){
			bck[l]=max(bck[l],bck[k]+getval(l,k-1));
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,max(fro[i]+bck[i+1],fro[i-1]+bck[i]));
	}
	printf("%lld\n",ans);
}
inline int getval(int l,int r){
	int t=Xor[r]^Xor[l-1];
	return t==k?1ll:0ll;
}
