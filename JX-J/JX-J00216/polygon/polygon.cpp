#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
int cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	ll ans=0;
	int a[5001] = {0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int m=3;m<=n;m++){
		for(int i=1;i<=n-m+1;i++){
		//	for(int j=1;j<=m;j++){

		//	}
		 	ll sum=0;
		 	for(int j=i;j<=i+m-1;j++){
		 		sum += a[j];
		// 		cout << a[j] << " ";
		 	}
		 	if(sum > a[i] * 2){
		 		ans++;
		// 		cout << a[i];
		 	}
		// 	cout << endl;

		}
		if(ans >= 998244353)ans -= 998244353;
	}
	ans = ans % 998244353;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}