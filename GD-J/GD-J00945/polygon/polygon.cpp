#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[5005][5005],n,a[5005],sum;
int Add(int x,int y){ return (x+y>=mod?x+y-mod:x+y); }
int main(){
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum=max(a[i]+1,sum);
	f[0][0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			f[i][j]=Add(f[i][j],f[i-1][j]);
			f[i][min(j+a[i],sum)]=Add(f[i][min(j+a[i],sum)],f[i-1][j]);
		}
		for(int j=sum;j>a[i];j--) ans=Add(ans,f[i-1][j]);
	}
	printf("%d",ans);
	return 0;
}
