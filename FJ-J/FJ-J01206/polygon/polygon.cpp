#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
long long zh;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zh+=a[i];
	}
	sort(a+1,a+n+1);
	if(zh>a[n]*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
