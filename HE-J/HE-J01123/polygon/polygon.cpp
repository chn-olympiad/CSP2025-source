#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-3;i++){
		ans+=i*i;
	}
	cout<<ans;
	return 0;
}

