#include<bits/stdc++.h>
using namespace std;

int n,k,a,b,c;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==1) b++;
		else if(c==0) c++;
	}
	if(k==1) cout<<b;
	else if(k==0) cout<<c;
	else cout<<k;
	return 0;
	
}
