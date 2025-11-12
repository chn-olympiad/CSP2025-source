#include <bits/stdc++.h>
using namespace std;
int n,a[5010],as;
int f(int i){
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a+0,a+n);
	for(int i=3;i<=n;i++){
		f(i);
		as%=998244353;
	}
	cout<<as;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

