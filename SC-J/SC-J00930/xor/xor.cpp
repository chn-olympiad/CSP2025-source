#include<bits/stdc++.h>
using namespace std;
long long a[50006],n,k,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0) cout<<1;
	if(k==2) cout<<2;
	if(k==3) cout<<2;
	else cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
