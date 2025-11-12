#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","e",stdin);
	int n,k,a[10009],q,w=0;
	cin>>n>>k;
	for(int z=1;z<=n;z++){
		cin>>a[z];
	}
	q=a[1];
	for(int z=2;z<=n;z++){
		if(a[z]>a[z-1]){
			q=a[z];
		}
	}
	cout<<q;
	return 0;
}
