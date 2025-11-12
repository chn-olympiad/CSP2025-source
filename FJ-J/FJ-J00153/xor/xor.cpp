#include<bits/stdc++.h>
using namespace std;
int n,k,a;
long long s1=0,s0=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==1) s1++;
		else if(a==0) s0++;
	}
	if(k==1) cout<<s1;
	else if(k==0) cout<<s0+s1/2;
	else cout<<0;
	return 0;
}
