#include<bits/stdc++.h>
using namespace std;

int n,a[5005],s,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
		s+=a[i];
	}
	if(n==3){
		if(s>2*m) cout<<1;
	}
	fclose(stdout);
	return 0;
} 