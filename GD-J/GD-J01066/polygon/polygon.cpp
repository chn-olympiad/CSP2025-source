#include <bits/stdc++.h>
#define ll long long
#define p 998244353
using namespace std;
int a[5005],n,pre[5005],mx,ans,inv[5005],sum,tmp,cnt,k,f[5005],g[5005][5005],l[5005][5005];
inline int mo(int x){
	if(x<0) return x+p;
	if(x>=p) return x-p;
	return x;
}
inline int qpow(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=1ll*sum*x%p;
		x=1ll*x*x%p;
		y>>=1;
	}
	return sum;
}
inline void read(int &x){
	char ch=getchar();
	if(ch>57||ch<48) ch=getchar();
	while(ch>=48&&ch<=57){
		x=x*10+(ch^48);
		ch=getchar();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		mx=max(mx,a[i]);
	} 
	sort(a+1,a+1+n);
	if(mx==1){
		for(int i=1;i<=n;i++) inv[i]=qpow(i,p-2);
		for(int i=3;i<=n;i++){
			ll tmp=1;
			for(int j=1;j<=i;j++) tmp=tmp*(n-j+1)%p*inv[j]%p;
			ans=mo(ans+tmp);
		}	
		printf("%d",ans);
	}
	else{
//		for(int i=7;i<(1<<n);i++){
//			k=cnt=mx=sum=0;
//			tmp=i;
//			while(tmp){
//				cnt++;
//				if(tmp&1){
//					mx=max(mx,a[cnt]);
//					sum+=a[cnt];
//					k++;
//				}
//				tmp>>=1;
//			} 
//			if(k<3) continue;
//			if((mx<<1)<sum) ans++; 
//		}
		g[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=mx+1;j++) g[i][j]=g[i-1][j];
			for(int j=a[i];j<=mx;j++) g[i][j]=mo(g[i][j]+g[i-1][j-a[i]]);
			g[i][mx+1]=mo(g[i][mx+1]+l[i-1][mx+1]-l[i-1][mx+1-a[i]-1]);
			for(int j=1;j<=mx+1;j++) l[i][j]=mo(l[i][j-1]+g[i][j]);
			if(i>2) f[i]=mo(f[i]+l[i-1][mx+1]-l[i-1][a[i]]);
		}
		for(int i=3;i<=n;i++) ans=mo(ans+f[i]);
		printf("%d",ans);
	}
	return 0;
}
