#include<bits/stdc++.h>
using namespace std;

long long n,k,a[500005],f,v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) v++;
		if(a[i]==a[i-1] and a[i]!=a[i+1]){
			v++;
			f+=v/2;
			v=0;
		}
	}
	cout<<f;
	
	
	return 0;
}
