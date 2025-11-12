#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,a[N],ma=INT_MIN;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ma=max(ma,a[i]);
	}
	cout<<ma;
	return 0;
}
