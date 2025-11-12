#include<bits/stdc++.h>
using namespace std;
int main(){//T3 2025/11/01 11:14:57 [5,10]pts.
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<0;
		return 0;
	}
	
	int a,b;
	cin>>a>>b;
	if(a==b)cout<<2;
	else if(a==0)cout<<1;
	else if(b==0)cout<<1;
	else cout<<0;
	return 0;
}
