#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const int N=5050;

int n,a[N];
lint s;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	s=lint(n)*(n-1)*(n-2)/6;
	cout<<s;
	
	return 0;
}
