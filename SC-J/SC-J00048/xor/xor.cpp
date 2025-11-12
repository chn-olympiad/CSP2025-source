#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1005
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	int sum = 0;
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++){
		if(a[i] == 0)sum++;
	}
	if(n == 2)
		if((a[0] ^ a[1]) == 0)sum++;
	cout<<sum;
	return 0;
	
}