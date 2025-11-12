#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5010];

int main(){
	freopen("polygon2.in","r",stdin);
	freopen("polygon2.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n] + a[n-1]<<endl;
	return 0;
}
