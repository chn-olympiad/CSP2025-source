#include <bits/stdc++.h>
using namespace std;
const int N = 115;
int a[N],n,m,tot;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot = n*m;
	for(int i = 1 ; i<=tot ; i++) scanf("%d",&a[i]);
	int tmp = a[1];
	sort(a+1,a+tot+1,cmp);
	for(int i = 1 ; i<=tot ; i++){
		if(a[i]==tmp){
			int l = (i-1)/n+1 , h = i%n == 0 ? n : i%n;
			if(l%2==0) h = n-h+1;
			printf("%d %d",l,h);
			break;
		}
	}
	return 0;
}