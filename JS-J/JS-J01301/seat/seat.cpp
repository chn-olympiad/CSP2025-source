#include<bits/stdc++.h>
using namespace std;
int n,m,a[100004];
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			cnt=i;
			break;
		}
	}
	printf("%d\n",(cnt-1)/n+1);
	if(((cnt-1)/n+1)%2==1){
		printf("%d",(cnt-1)%n+1);
	}
	else{
		printf("%d",n-(cnt-1)%n);
	}
	return 0;
}
