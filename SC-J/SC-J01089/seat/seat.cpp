#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	int xx=1,yy=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==R){
			printf("%d %d",yy,xx);
			break;
		}
		if(yy&1){
			if(xx!=n) xx++;
			else yy++;
		}else{
			if(xx!=1) xx--;
			else yy++;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}