#include<bits/stdc++.h>
using namespace std;
long long a[100010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
	return 0;
}

