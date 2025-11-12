#include <bits/stdc++.h>
using namespace std;
int n,m,sc,a[105],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++){
		scanf("%d",&a[i]);
	}sc = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i = 1;i <= n * m;i++){
		if(a[i] == sc){
			p = i;
			break;
		}
	}int l = p / n + 1,h = p % m;
	if(h == 0){
		l--;
		h += m;
	}if(l & 1){
		printf("%d %d",l,h);
	}else{
		printf("%d %d",l,m - h + 1);
	}return 0;
}
