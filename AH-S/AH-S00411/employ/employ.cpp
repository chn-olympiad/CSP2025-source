#include <cstdio>
using namespace std;

char a[505];
int n,m,c[505],ny[505],ans=1,mod=998244353;
int kuai(int a,int k){
	if(k==1) return a%mod;
	if(k==0) return 1;
	if(k%2==1) return kuai(a,k/2)%mod*kuai(a,k/2)*a%mod;
	else return kuai(a,k/2)%mod*kuai(a,k/2)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int k=0;
	scanf("%s",a+1);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	for(int i=1;i<=n;i++) if(!c[i]) k++;
	if(n-m<k) ans=0;
	else {
		for(int i=1;i<=n;i++) ans=ans*i%mod;
	}
	printf("%d\n",ans);
	return 0;
}
