#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N= 5e5+10;
int arr[N],sum[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^arr[i];
	}
	int f=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=f;j--){
			if((sum[i]^sum[j-1])==k){
				ans++;f=i+1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}