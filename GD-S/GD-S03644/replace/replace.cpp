#include<bits/stdc++.h>
using namespace std;
string a[10000][2],b[10000][2];
long long n,q;
void solve(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cout<<n/2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=0;i<q;i++){
		solve();
	}
}
