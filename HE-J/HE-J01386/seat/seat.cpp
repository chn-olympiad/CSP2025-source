#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[110];
void Psnake(int t){
	int x=0;
	x=2*int(t/(2*n));
	t=t%(2*n);
	if(t==0)
		printf("%d 1",x);
	else if(t<=n)
		printf("%d %d",x+1,t);
	else{
		printf("%d %d",x+2,n+n-t+1);
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	for(int i=1;i<=n*m-1;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m);
	a[n*m]=101;	
	for(int i=0;i<=n*m;i++){
		if(a[i]<R&&a[i+1]>R)
			Psnake(n*m-i);
	}
	return 0;
}
