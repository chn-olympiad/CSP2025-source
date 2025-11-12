#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	int m,n,a[503];
	string sh;
	cin>>n>>m;
	cin>>sh;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>a[n]*2){
		cout<<n/2;
	}else{
		cout<<a[n];
	}
}
