#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1000];
int a[1000];
int c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	long long ans=1;
	int cnt=0;
	for(int i=n;i;i--){
		if(s[i]=='1'){
			int id;
			while(a[id]>i)id--;
			ans*=(n-id-cnt);
			ans%=998244353;
			cnt--;
		}
	}
	printf("%lld",ans);
	return 0;
}
