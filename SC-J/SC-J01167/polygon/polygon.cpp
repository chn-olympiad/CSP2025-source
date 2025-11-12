#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int a[N],s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]<=a[3]) cout<<0;
		else cout<<1;
	} 
	else{
		cout<<n-2; 
	}
	return 0;
}