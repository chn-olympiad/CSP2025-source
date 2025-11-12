#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i-1]==k){
			s++;
			continue;
		}
		a[i]^=a[i-1];
	}
	if(a[n]==k){
		s++;
	}
	cout<<s;
	return 0;
}

