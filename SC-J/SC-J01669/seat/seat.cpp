#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10;

struct node{
	int num,id;
} a[N];

int n,m,l = 0,r = 1;

bool cmp(node a,node b){
	return a.num > b.num;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n * m;i++)
		scanf("%lld",&a[i].num),a[i].id = i;
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(l % 2 == 0 && r == 1) l++;
		else if(l % 2 == 1 && r == n) l++;
		else if(l % 2 == 0) r--;
		else r++;
		if(a[i].id == 1){
			printf("%lld %lld\n",l,r);
			return 0;
		}
	}
	return 0;
}