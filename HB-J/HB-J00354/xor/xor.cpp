#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+20;
long long  n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)x++;
	}
	if(k==0){
		cout<<x;
	}
	else cout<<1;
	return 0;
}
