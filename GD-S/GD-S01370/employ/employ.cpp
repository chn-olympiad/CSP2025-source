#include<bits/stdc++.h>
using namespace std;
long long a[100000000],k=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	string a;
	cin>>n>>a;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=1; i<=n; i++){
		k*=i;
		k%=998244353;
	}
	cout<<k;
}
