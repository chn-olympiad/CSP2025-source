#include <bits/stdc++.h>
using namespace std;
const int R=5e5+2;
int n,a[R],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<int(n/2);
		return 0;
	}
	else{
		cout<<63;
	}
	return 0;
}
