#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int num = 0;
	for(int i = 1;i < n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		num+=a[i]^a[i+1];
		if(num==k){
			ans++;
			num = 0;
		}	
	}
	cout<<++ans;
	return 0;
}	
