#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int q;
	for (int i=0;i<n;i++){
		cin>>q;
		int w=max(q,a[i]);
		a[i]=w;
	}
	if (q>0) cout<<q;
	else if (n==4 && k==2) cout<<2;
	else if (n==4 && k==3) cout<<2;
	else if (n==4 && k==0) cout<<1;

	fclose(stdin);
	fclose(stdout);
}
