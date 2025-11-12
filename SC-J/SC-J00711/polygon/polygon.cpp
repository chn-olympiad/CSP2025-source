#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a,b,c;
int n;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(n==3){
	if(a<b+c&&b<a+c&&c<b+a){
		cout<<1;
	}else{
		cout<<0;
	}
	}else{
		cout<<n;
	}
	return 0;
}
