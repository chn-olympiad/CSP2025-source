#include<bits/stdc++.h>
using namespace std;
long long a,k,ans;
bool s[5*1000000+5];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a[i]==k) ans++;
		s[i]=bool(a);
	}
	cout<<ans;
	return 0;
} 
