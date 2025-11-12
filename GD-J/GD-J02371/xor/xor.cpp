#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long cnt=0;
long long a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		long long ans=a[i];
		if(a[i]==k){
			cnt++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			ans^=a[j];
			if(ans==k){
				i=j+1;
				cnt++;
				break;
			}			
		}
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
