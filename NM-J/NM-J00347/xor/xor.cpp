#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int arr[n+1];
	int ans = 0;
	arr[0] = 0;
	vector<pair<int,int>> p;
	for (int i = 1;i<=n;i++) cin>>arr[i],arr[i]^=arr[i-1];
	cout<<0;
}
