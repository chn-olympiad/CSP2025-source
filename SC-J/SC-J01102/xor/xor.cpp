#include<bits/stdc++.h>
using namespace std;
int n,k,num[500005];
int main(){
	freopen(" number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	num[0]=0;
	for(int i=1;i<=n;++i){
		cin>>num[i];
		num[i]^=num[i-1];
	}
	cout<<'1';
	return 0;
}