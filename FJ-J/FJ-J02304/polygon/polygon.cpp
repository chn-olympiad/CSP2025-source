#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;
int a[5005];
int b[5005][5005];
int ans;
bool flag;
void f(int l,int r,int sum,int m,int x){
	if(l>r){
		if(sum>m*2) ans=(ans+1) % M;
		return;
	}
	for(int i=x;i<=n-(r-l);i++)
		f(l+1,r,sum+a[i],max(m,a[i]),i+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) flag=1;
	}
	sort(a+1,a+n+1);
	if(!flag){
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=i-2;
			b[i][3]=b[i-1][3]+cnt;
			for(int j=4;j<=i;j++){
				b[i][j]=(b[i-1][j-1]+b[i-1][j])%M;
				if(i==n) ans=(ans+b[i][j])%M;
			}
		}
		printf("%d",(ans+b[n][3])%M);
	}else{
		for(int i=3;i<=n;i++)
			f(1,i,0,0,1);
		printf("%d",ans);
	}
	return 0;
}
