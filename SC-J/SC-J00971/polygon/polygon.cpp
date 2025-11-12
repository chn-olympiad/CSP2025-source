#include<bits/stdc++.h>
using namespace std;
int n,a[10010],ans,num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
		ans=max(ans,a[i]);
	}
	if(num>ans*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 