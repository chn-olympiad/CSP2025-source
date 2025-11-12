#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k,t=1,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++; 
	}
	if(k==0)cout<<cnt/2;
	else cout<<cnt;
	return 0;
}
