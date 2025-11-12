#include<bits/stdc++.h>
using namespace std;
int n,m,q,a2;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	q=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			q=n*m-i+1;
			break;
		}
	}
	int a1=(q+n-1)/n;
	if(a1%2==1){
		a2=q%n;
		if(a2==0)a2=n;
	}else{
		a2=q%n;
		if(a2==0)a2=n;
		a2=n-a2+1;
	}
	printf("%d %d",a1,a2);
	return 0;
}
