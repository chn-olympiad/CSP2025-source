#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+2;
long long a[N],q; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(q == 0){
		cout<<0;
		return 0;
	}
}

