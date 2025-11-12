#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k;
int a,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==1) a++;
		if(x==0) b++;
	}
	if(k==1) cout<<a;
	if(k==0) cout<<b+a/2;
	return 0;
}
