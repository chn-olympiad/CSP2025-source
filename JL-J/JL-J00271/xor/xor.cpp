#include<bits/stdc++.h>
using namespace std;
long long n,a[1000443],m,s=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			s++;
		}
	}
	cout<<s;
	return 0;
}
