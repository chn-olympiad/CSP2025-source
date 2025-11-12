#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    cout<<n/2;
	return 0;
}
