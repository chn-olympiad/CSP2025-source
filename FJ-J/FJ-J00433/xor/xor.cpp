#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N],ans;
vector<pair<int,int>> g;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k,n;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	int pre=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>pre;j--){
			if((s[i]^s[j-1])==k){
				ans++;
				pre=i;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

