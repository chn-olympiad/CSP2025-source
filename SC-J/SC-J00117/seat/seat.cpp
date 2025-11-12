#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[115];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,b,e;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m*n;i++){
		scanf("%d",&a[i]);
	}
	b=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==b){
			e=i;
		}
	}
	long long f=e/n+1,g;
	if(e%n==0){
		f-=1;
	}
	if(e%n==0){
		g=n;
	}
	else if(f%2==0){
		g=n+1-e%n;
	}
	else{
		g=e%n;
	}
	printf("%d %d",f,g);
	return 0;
} 