#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005]= {};
	int b[500005]= {};
	cin>>a[0];
	b[0]=a[0];

	for(int i=1; i<n; i++) {
		cin>>a[i];
		b[i]=a[i]|b[i-1];
	}
	int o=0;int j=0;int c=0;int ans=0;
	for(int i=0; i<n; i++) {
		if(b[i]==k){
		o++;j=i;}
		else  {
			
			ans=i;
			while(ans>j)
			{
				
				if(b[i]-b[j+c]==k){
					o++;j=i;c=0;ans=0;
					break;
				}c++;ans--;
			}
			
		}
		}

	
	cout<<o;
	return 0;
}
