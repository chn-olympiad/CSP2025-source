#include <bits/stdc++.h>
#include <vector>
#define Long long long
#define NL 5001
#define MOD 998244353
using namespace std;

int n;
int arr[NL];

int dfs(int tot,int si,int deep) {
	int res = 0;
	for (int i=si;i<n;i++) {
		if (tot > arr[i] && deep >= 3) {
			res++;
		}
		res += dfs(tot+arr[i],i+1,deep+1);
	}
	return res%MOD;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",arr+i);
	}
	sort(arr,arr+n);
	printf("%d",dfs(0,0,1));
	
	return 0;
}
