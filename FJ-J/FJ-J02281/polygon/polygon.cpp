#include <bits/stdc++.h>
using namespace std; 

int a[5000 + 5];
int n;
const int MOD =  998244353;
int sum = 0;	
//       个数   下标    最大值    和 
void dfs(int x,int num,int maxx,int summ) {
	
	if(num >= n + 2) return ;
	//cout << x << " " << maxx << " "<<summ<<"\n";	
	if(x >= 3 && maxx * 2 < summ) {
		sum++,sum %= MOD;
		//cout<<"efesfs\n";
	}
	//加上他
	dfs(x + 1,num + 1,max(maxx,a[num]),summ + a[num]);
	//不加
	dfs(x,num + 1,maxx,summ); 
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	if(n < 3) {
		printf("0");
		return 0;
	}
	if(n == 3) {
		sort(a + 1,a + n + 1);
		if(a[1] + a[2] > a[3]) {
			printf("1");
		}else {
			printf("0");
		}
		return 0;
	}
	dfs(0,1,0,0);
	printf("%d",sum - 2);
}
