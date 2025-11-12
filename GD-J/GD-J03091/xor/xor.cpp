#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}else{
			long long x=a[i];
			for(int r=i+1;r<=n;r++){
				for(int l=i;l<=r;l++){
					x^=a[l];
				}
			}
			if(x==k){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
