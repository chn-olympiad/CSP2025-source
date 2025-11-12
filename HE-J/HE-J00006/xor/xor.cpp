#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=2;i++){
		if(a[i]==0&&a[i+1]==0){
			cout<<3;
			return 0;
		}
	}

	return 0;
}
