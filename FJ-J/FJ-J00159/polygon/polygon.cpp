#include<bits/stdc++.h>
using namespace std;
int n,a[100100],m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) m+=a[i];
	m--;
	cout<<m;
	return 0;
}
