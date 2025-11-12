#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	scanf("%d%d%d",&n,&m,&a1);
	a[1]=a1;
	for(int i=2;i<=n*m;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n*m);
	/*for(int i=1;i<=n*m;i++)printf("%d ",a[i]);
	printf("\n");*/
	int c=1,r=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==a1){
			printf("%d %d",c,r);
			return 0;
		}
		if(((c&1)&&(r==n))||((!(c&1))&&(r==1)))c++;
		else if(c&1)r++;
		else if(!(c&1))r--;
	}
	return 0;
}
/*
2 2
98 99 100 97
*/
