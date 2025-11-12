#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<(3^1);
	scanf("%lld%lld",&n,&k);
	long long a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	vector<long long> t;
	for(int i=1;i<=n;i++){
		t.push_back(0);
		long long len=t.size();
		for(int j=0;j<len;j++){
			t[j]=(t[j]^a[i]);
			if(t[j]==k){
				ans++;
				t.clear();
				break;
			}			
		}
	}
	printf("%lld",ans);
	return 0;
}
