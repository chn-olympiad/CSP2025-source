#include<bits/stdc++.h>
using namespace std;

int i,a[200],j,n,m,r,ans,x,y;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i = 1;i <= n * m;i++){
		scanf("%d",&a[i]);
	}
	r = a[1];
	sort(a + 1,a + n * m + 1);
	for(i = n * m;i >= 1;i--){
		if(r < a[i]) ans++;
	}
	x = ans / n + 1;
	y = ans % n + 1;
	if(x % 2 == 0){
		printf("%d",x);
		cout << " ";
		printf("%d",m - y + 1);
	}
	else{
		printf("%d",x);
		cout << " ";
		printf("%d",y);
	}
	return 0;
}