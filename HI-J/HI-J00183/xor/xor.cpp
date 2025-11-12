#include<bits/stdc++.h>
using namespace std;
int n, k,z;
int a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			z=max(z,a[i]);
		}
	}
	
	if(z!=0)
	cout<<z<<endl;
	else
	cout<<1<<endl;
	return 0;
}

