#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=m*n-i;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<+n*m;i++)
		if(a[i]==x){
			x=i;
			break;
		}
	int nn,mm;
	if(x%n==0)mm=x/n;
	else mm=x/n+1;
	if(mm%2==0)nn=n-(x%n)-1;
	else nn=(x%n);
	if(nn==0)nn=n;
	printf("%d %d",mm,nn);
	return 0;
}
