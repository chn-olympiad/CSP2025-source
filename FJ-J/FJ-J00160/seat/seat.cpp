#include<bits/stdc++.h>
using namespace std;
int m,n,a[10000],a1;
int SeatNum(int x,int y){
	if(x%2==1)return y+(x-1)*n-1;
	return m-y+(x-1)*n;
}
int main(){
	freopen("seat2.in","r",stdin);
	freopen("seat2.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m*n;i++)scanf("%d",&a[i]);
	a1=a[0];
	sort(a,a+m*n);
	for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--)if(a1==a[SeatNum(i+1,j+1)])printf("%d %d",m-i,j+1);
	return 0;
}
