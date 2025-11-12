#include<bits/stdc++.h>
using namespace std;
long long n,k,a,q[500050],z;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a;
		q[i]=a^q[i-1];
		if(q[i]==k){
			++z;
			q[i]=0;
		}
		a=0;
		
	}
	cout<<z;
	return 0;
} 
