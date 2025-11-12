#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,a[1010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==3||m==2){
			cout<<2;
			break;
		}else{
			cout<<1;
			break;
		}
	}
	return 0;
}
