#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,k,o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m),k=n*m;
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	o=a[1];
	sort(a+1,a+1+k);
	for(int i=1,j=k;i<=k&&j>=1;j--,i++)
		if(o==a[j]){
			int r=(i+n-1)/n,c=i%n;
			if(c==0) c=n;
			printf("%d ",r);
			if(r%2==1) printf("%d",c);
			else printf("%d",n-c+1);
			return 0;
		}
	return 0;
} 
