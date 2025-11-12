#include<bits/stdc++.h>
using namespace std;
constexpr int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5050];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cout<<a[n]+a[n-1];
	return 0;
}
