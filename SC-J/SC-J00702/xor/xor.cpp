#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;char v=getchar();int f=1;
	while(v<'0'||v>'9'){
		if(v=='-') f=-1;
		v=getchar();
	}
	while(v>='0'&&v<='9'){
		x=(x<<1)+(x<<3)+(v&15);
		v=getchar();
	}
	x*=f;
}
const int N = 500010;
int n,k;
int a[N];
int qzh[N],ans=0,l;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]),qzh[i]=qzh[i-1]^a[i];
	int l=0,sum;
	for(int i=1;i<=n;i++){
		sum=qzh[i]^k;
		for(int j=l;j<=i-1;j++){
			if(qzh[j]==sum){
				l=i,ans++;
				i=l;
				break;
			} 
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}