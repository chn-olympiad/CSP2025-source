#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,k[5000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	if(k[1]+k[2]>k[0]){
		cout<<1;
	}
	else cout<<0;
	return 0;
}