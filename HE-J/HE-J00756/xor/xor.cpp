#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n;
	long long int k;
	cin >>n>>k;
	long long int a[500011];
	for(int i=0;i<n;i++) cin >>a[i]; 
	if(k==0) cout<<n;
	return 0;
}
