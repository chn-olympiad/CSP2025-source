#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c = 0;
	cin>>n>>k;
	int a[n+5];
	for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] == 0) c++;
	}
	cout<<c;
	return 0;
}
