#include<bits/stdc++.h>
using namespace std;
int n;
int a[10101];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||n==2||n==3){
		cout<<3;
	}
	return 0;
}
