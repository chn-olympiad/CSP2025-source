#include<bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> a[111];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++){
		int x;
		scanf("%d",&x);
		a[i].first = -x;
		a[i].second = i;
	}
	sort(a + 1,a + n * m + 1);
	int k;
	for(int i = 1;i <= n * m;i++){
		if(a[i].second == 1){
			k = i;
			break;
		}
	}
//	printf("%d\n",k);
	int t = (k - 1) / n;
	k = (k - 1) % n + 1;
	if(t % 2 == 1){
		printf("%d %d",t + 1,n - k + 1);
	}else{
		printf("%d %d",t + 1,k);
	}
	return 0;
}