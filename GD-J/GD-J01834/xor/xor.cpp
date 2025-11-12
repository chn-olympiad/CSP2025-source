#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
bool all1=1;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) all1=0;
	}
	if(all1) cout<<n/2;
	//fclose(stdout);
	//fclose(stdin);
	return 0;
}
