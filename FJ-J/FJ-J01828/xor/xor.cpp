#include <bits/stdc++.h>

using namespace std;

long long n,k,a[500005],pre,cnt;
vector<long long> g[500005];
long long f1(long long be,long long en){
	long long ans=pre;
	for(int i=1;i<be;i++){
		ans^=a[i];
	}
	for(int i=en+1;i<=n;i++){
		ans^=a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	pre=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		pre^=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long an=f1(i,j);
			if(an==k){
				i=j+1;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
