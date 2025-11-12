#include<bits/stdc++.h>
using namespace std;
long long a[1005];	
long long n,k,s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s++;	
		}
	}
	cout<<s;
}
