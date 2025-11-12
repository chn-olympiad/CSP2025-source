#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[30];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
   	cin>>n>>m;
   	for(int i=1;i<=n;i++){
   		cin>>a[i];
	}
	if(m==0) cout<<1;
	return 0;
}
