#include <bits/stdc++.h>
using namespace std;
int a[500005]; 
int n, k, ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			if(i==j){
				sum=a[i];
			} else{
				for(int c=i;c<=j;c++){
					sum=(sum^a[c]);
				}
			}
			if(sum==k){
				ans++;
				i=j;
				break;
			}
		}
	} 
	printf("%d", ans); 
	return 0;
}
