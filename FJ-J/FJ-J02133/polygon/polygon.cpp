#include <bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int n;
int a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	
	long long sum=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				int s=a[i]+a[j];
				int idx=i;
				while (s<=a[k]&&idx>=1){
					s+=a[--idx];
				}
				if (!idx) continue;
				sum++;
				sum+=idx*(idx-1)/2;
				sum%=MOD;
			}
		}
	}
	printf("%lld\n",sum);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
