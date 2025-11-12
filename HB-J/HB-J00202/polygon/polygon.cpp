#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
void solve(){
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b>c&&b+c>a&&a+c>b) cout<<1;
    else cout<<0;
	
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
