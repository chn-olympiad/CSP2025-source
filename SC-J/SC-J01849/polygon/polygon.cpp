#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

const int N=5010,MOD=998244353;

int n,m;
int a[N],f[N][N];

void add(int &a,int b){
	(a+=b)>=MOD?a-=MOD:0;
}
int main(){
	Fre("polygon");
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1);
	m=a[n];
	f[0][0]=1;
	int res=0,mul=1;
	for(int i=1;i<=n;++i,add(mul,mul)){
		for(int j=0;j<=m;++j){
			f[i][j]=f[i-1][j];
			if(j>=a[i]) add(f[i][j],f[i-1][j-a[i]]);
		}
		add(res,mul);
		for(int j=0;j<=a[i];++j) add(res,MOD-f[i-1][j]);
	}
	printf("%d\n",res);
	
	return 0;
}