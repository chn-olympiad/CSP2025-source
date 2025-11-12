#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,m,tmp,x,y;
int a[N],f[N][N],s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++)
			f[i][j]=
	}
}
