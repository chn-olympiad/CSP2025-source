#include<bits/stdc++.h>
using namespace std;

int n,m,temp,cnt;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[(i-1)*m+j]);
	temp=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==temp){
			cnt=n*m-i+1;
			break;
		}
	}
	if((cnt-1)%(2*n)+1<=n) printf("%d %d",(cnt+n-1)/n,(cnt-1)%n+1);
	else printf("%d %d",(cnt+n-1)/n,n-((cnt-1)%n));
	return 0;
} 
