#include<bits/stdc++.h>
using namespace std;
const int N=5050;
long long a[N];
int n;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}
