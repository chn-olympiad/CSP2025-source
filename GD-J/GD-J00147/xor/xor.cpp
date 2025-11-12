#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)
const int N = 5E5+5;

int n,k;
int arr[N],sum[N];
set<int> se;
int las,ans;

int main(){
	in("xor.in");
	out("xor.out");
	se.insert(0);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		sum[i] = sum[i-1]^arr[i];
		if (se.find(sum[i]^sum[las]^k) != se.end()){
			ans++;
			las = i;
			se.clear();
			se.insert(0);
		}else{
			se.insert(sum[i]^sum[las]);
		}
	}
	printf("%d",ans);
	return 0;
}
/*

4 0
2 1 0 3

*/ 
