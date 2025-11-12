#include<bits/stdc++.h>
using namespace std;
string s;
int a[200000],j=1,x,n,m;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	while(a[j]!=x) j++;
	int lie=ceil((j*1.0)/(n*1.0)),hang=0;
	if(j%n==0){
		if((j/n)%2) hang=n;
		else hang=1;
	}
	else{
		if(lie%2==0) hang=(n-j%n+1);
		else hang=j%n;
	}
	printf("%d %d",lie,hang);
	return 0;
}
