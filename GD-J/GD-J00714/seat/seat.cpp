#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,a[101],s[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i&1)for(int j=1;j<=n;j++){
			s[j][i]=a[++k];
			if(s[j][i]==t){
				printf("%d %d",i,j);
				return 0;
			}
		}else for(int j=n;j;j--){
			s[j][i]=a[++k];
			if(s[j][i]==t){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
