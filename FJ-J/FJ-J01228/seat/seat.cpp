#include<bits/stdc++.h>
using namespace std;
int n,m,s,r,a[105],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	s=n*m;
	for(int i=1;i<=s;i++){
		scanf("%d",a+i);
	}
	r=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	ans=(r-1)/n+1;
	printf("%d ",ans);
	if(ans%2){
		printf("%d",(r-1)%n+1);
	}
	else{
		printf("%d",n-(r-1)%n);
	}
	return 0;
}

