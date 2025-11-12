#include<bits/stdc++.h>
using namespace std;

int n,k,last,ans,x;

int a[500500],c[500500],s[2500000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for( int i=1; i<=2500000; ++i ){
		s[i]=-1;
	}
	for( int i=1; i<=n; ++i ){
		cin>>a[i];
		c[i]=a[i]^c[i-1];
		x=c[i]^k;
		if( s[x]>=last ){
			++ans;
			last=i;
		}
		s[c[i]]=i;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}