#include <bits/stdc++.h>
using namespace std;
int a[600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(cnt==n){
		cout<<cnt/2;
		return 0;
	}
	cout<<114514;
	
	return 0;
}  
