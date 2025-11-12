#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/3;
	return 0;
} 
