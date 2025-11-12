#include<bits/stdc++.h>
using namespace std;
int n,f;
int a[100005],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(f = (1 << n) - 1;f > 0 ;f--){
		int sum = 0,maxx = 0;
		for(int i = 1;i <= n;i++){
			if( ((f >> (i - 1)) & 1)){
				sum += a[i];
				maxx = max(a[i],maxx);
			}
		}
		if(maxx * 2 < sum){
			ans++;
		}
//			for(int i = 1;i <= n;i++){
//				cout << ((f >> i) & 1);
//			}	cout << '\n';
	}
	
	printf("%d",ans);
	return 0;
}

