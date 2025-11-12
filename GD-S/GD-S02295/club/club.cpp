#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	struct node1{
		int n, i;
	}a[3];
}a[100010];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, ans=0, d[3]={0};
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d", &a[i].a[0].n, &a[i].a[1].n, &a[i].a[2].n);
			a[i].a[0].i=0;
			a[i].a[1].i=1;
			a[i].a[2].i=2;
			sort(a[i].a, a[i].a+3, [](node::node1 n1, node::node1 n2){
				return n1.n>n2.n;
			});
		}
		sort(a, a+n, [](node n1, node n2){
			return n1.a[0].n-n1.a[1].n==n2.a[0].n-n2.a[1].n?n1.a[0].n>n2.a[0].n:n1.a[0].n-n1.a[1].n>n2.a[0].n-n2.a[1].n;
		});
		for(int i=0;i<n;i++){
			if(d[a[i].a[0].i]<n/2){
				d[a[i].a[0].i]++;
				ans+=a[i].a[0].n;
			}else{
				d[a[i].a[1].i]++;
				ans+=a[i].a[1].n;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
