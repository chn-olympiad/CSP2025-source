#include<bits/stdc++.h>
using namespace std;
long long n=1,m,a[10000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=0,ans=0;
	for(int i=1;i<=n;i++){
		k=k^a[i];
		if(m==k){
			ans++;
			k=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/
