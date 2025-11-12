#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int s1=0,s0=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		if(u==0)s0++;
		else s1++;
	}
	if(k)cout<<s1;
	else cout<<s1/2+s0/2;
	return 0;
}
//he yi wei
