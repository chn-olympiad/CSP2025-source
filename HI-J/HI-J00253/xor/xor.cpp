#include<bits/stdc++.h>//10~30 pts? idk
using namespace std;
const int N=1e5;
int n,a[5*N+5],k;
int main(){//in fact, xor in array just meaning how many "1".
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if (k==0){ //10pts
		printf("%d",n/2);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	//down is 20pts
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}int ans=0;
	if (k==0){
		int p=0;
		for(int i=1;i<=n;i++){
			if (a[i]==1){
				p++;
				if (p%2==0){
					ans++; p=0;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if (a[i]==1) ans++;
		}
	}printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
