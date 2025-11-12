#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,k,cnt,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x) cnt++;
		else sum++;
	}
	if(k) cout<<cnt<<"\n";
	else cout<<cnt/2+sum<<"\n";

	return 0;
}

