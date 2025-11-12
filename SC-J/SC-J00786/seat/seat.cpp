#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,num,p,a[N];
bool cmp(int lhs,int rhs){
	return lhs>rhs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(num==a[i]){
			p=i;
			break;
		}
	}
	int l=p/n+(p%n>0),h=(l%2==1?(p%n==0?n:p%n):n-p%n+1);
	printf("%d %d\n",l,h);
	return 0;
}
