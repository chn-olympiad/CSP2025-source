#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int n,a[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[1]*a[n]/2; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
}
