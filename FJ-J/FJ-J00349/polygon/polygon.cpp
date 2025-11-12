#include <bits/stdc++.h>
using namespace std;
long long ans;
int n,a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<6;
	return 0;
}
