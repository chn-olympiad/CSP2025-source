#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int n;
	bool is;
}a[114];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<n*m;i++)scanf("%d", &a[i].n);
	a[0].is=1;
	sort(a, a+n*m, [](node n1, node n2){
		return n1.n>n2.n;
	});
	int k;
	for(int i=0;i<n*m;i++)if(a[i].is)k=i;
	printf("%d ", k/m+1);
	if(k/m%2)printf("%d", n-k%m);
	else printf("%d", k%m+1); 
	return 0;
}
