#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
const long long mod=998244353;
long long jc[505]={1,1},n,m,ld[505],ton[505]={0},ton1[505]={0};
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i=2;i<=500;i++)jc[i]=i*jc[i-1]%mod;
	scanf("%d %d %s",&n,&m,&s);
	for(int i=0;i<n;i++){
		if(s[i]-'0'){
			ld[++ld[0]]=i+1;
		}
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ton[x]++;
	}
	for(int i=n-1;i>=1;i--)ton1[i]=ton[i]+ton[i+1];
	
	printf("%d",jc[n]);
	return 0;
}