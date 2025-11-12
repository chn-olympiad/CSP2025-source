#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],xx,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(a[i] == 0) xx++;
	}
	if(k == 0){
		printf("%d",xx);
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		if(a[i] == k){
			ans++;
		}
		for(int j = i+1; k < n; k++){
			cnt = a[i] ^ a[j];
			if(cnt == k){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
