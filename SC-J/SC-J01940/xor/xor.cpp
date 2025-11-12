#include<bits/stdc++.h>
using namespace std;

int n,k,a[200100],b[1010],f[1010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int ok1 = 1,ok2 = 1;
	for(int i = 1;i <= n;i++){
		if(a[i] != 1){
			ok1 = 0;
		}
		if(a[i] > 1){
			ok2 = 0;
		}
	}
	if(k > 1){
		ok2 = 0;
	} 
	if(ok1){
		if(k == 0){
			printf("%d",n / 2);
			return 0;
		}else if(k == 1){
			printf("%d",n);
		}else{
			printf("0");
		}
		return 0;
	}
	if(ok2){
		if(k == 1){
			int ans = 0;
			for(int i = 1;i <= n;i++){
				ans += a[i];
			}
			printf("%d",ans);
		}else{
			int i = 1,ans = 0;
			while(i <= n){
				if(a[i] && a[i + 1]){
					ans++;
					i++;
				}
				if(!a[i]){
					ans++;
				}
				i++;
			}
			printf("%d",ans);
		}
		return 0; 
	}
	for(int i = 1;i <= n;i++){
		int x = 0;
		for(int j = i;j <= n;j++){
			x = x ^ a[j];
			if(x == k){
				b[i] = j;
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		f[b[i]] = max(f[i - 1] + 1,f[b[i]]);
		f[i + 1] = max(f[i + 1],f[i]);
	}
//	for(int i = 1;i <= n;i++){
//		printf("%d ",f[i]);
//	}
	printf("%d",f[n]);
	return 0;
}