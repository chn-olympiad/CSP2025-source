#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m,x=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		x*=i+1;
		x%=998244353;
	}
	cout<<x;
	return 0;
}
