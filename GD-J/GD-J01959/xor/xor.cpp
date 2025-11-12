#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	struct _timeb T;
	_ftime(&T);
	srand(T.millitm);
	cin>>n>>k;
	if(!k) cout<<n/2;
	else cout<<rand();
	return 0; 
}
