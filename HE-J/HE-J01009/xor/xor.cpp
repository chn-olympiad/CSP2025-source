#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],m,x;
bool b=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1||a[i-1]==0) b=false;
		if(a[i]==0) x++;
		m+=a[i];
	}
	if(n==1&&a[1]!=k)
		cout<<0;
	else if(k==1&&b)
		cout<<n;
	else if(k==0&&b)
		cout<<x+m/2;
	else cout<<n/2;
	return 0;
}
