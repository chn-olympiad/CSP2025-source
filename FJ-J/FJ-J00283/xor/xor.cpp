#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=1;
	cin>>n>>k;
	if(k==0)
		cout<<1<<endl;
	else if(k==1){
		while(x*2<=n)
			x*=2;
		cout<<x-1<<endl;
	}
	else
		cout<<2<<endl;
	return 0;
}
