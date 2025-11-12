#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[114]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	//ErFenDouBuYong???
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	printf("%d %d",(t-1)/n+1,(((t-1)/n+1)%2==0)?((t%n==0)?1:(n-t%n+1)):((t%n==0)?n:(t%n)));
	//(((t-1)/n+1)%2==0)?((t%n==0)?1:(n-t%n)):(n-t%n+1)
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
