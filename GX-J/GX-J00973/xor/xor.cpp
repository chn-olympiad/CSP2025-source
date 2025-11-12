

#include <bits/stdc++.h>
using namespace std;
int n,s;
long long m[1000000],k;
int main()
{	freopen("xor.in","r",in);
	freopen("xor.out","w",out);
	
	cin>>n>>k;
	long long a;
	cin>>m[1];
	for(long long i=1;i<=n;i++){
		cin>>a;
		m[i]=m[i-1]^a;
	}	
	for(long long i=1;i<=n;i++){
		for(long long j=1;i<n;j++){
			if((m[j]^m[i])==k) s++;
		}	
	}
	
	cout<<s;
	return 0;
}

