#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int n, ft, bk;
}a[500010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)scanf("%d", &a[i].n);
	for(int i=0;i<n;i++){
		a[i].ft=i;
		int j=i+1, _xor=a[i].n;
		for(j;j<n&&_xor!=k;j++)_xor^=a[j].n;
		if(_xor==k)a[i].bk=j-1;
		else a[i].bk=1e9;
	}
	sort(a, a+n, [](node n1, node n2){
		return n1.bk<n2.bk;
	});
	int bk=-1, ans=0;
	for(int i=0;i<n;i++)if(a[i].bk<n&&a[i].ft>bk){
		ans++;
		bk=a[i].bk;
	}
	printf("%d", ans);
	return 0;
}
