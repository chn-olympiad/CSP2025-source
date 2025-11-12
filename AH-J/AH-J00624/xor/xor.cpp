#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int xo=0;
	for(int i=0;i<n;i++){
		xo=xo^a[i];
		if(xo==m){
			ans++;
			xo=0;
		}
	}
	cout<<ans;
	return 0;
}
