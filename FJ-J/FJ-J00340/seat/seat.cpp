#include <bits/stdc++.h>
using namespace std;
bool cmp(int q,int p){
	return q > p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105] = {};
	scanf("%d %d",&n,&m);
	for (int i = 1;i <= n * m;i++){
		scanf("%d",&a[i]);
	}
	int t = a[1];
	int z;
	sort(a + 1,a + 1 + (n * m),cmp);
	for (int i = 1;i <= n * m;i++){
		if (a[i] == t){
			z = i;
			break;
		}
	}
	
	int m1 = ceil(z * 1.0 / n);
	int n1;
	if (m1 % 2 == 1){
		n1 = z % n;
		if (n1 == 0){
			n1 = n;
		}
	}else{
		n1 = n + 1 - (z % n);
		if (n1 == n + 1){
			n1 = 1;
		}
	}
	printf("%d %d",m1,n1);
	return 0;
} 
