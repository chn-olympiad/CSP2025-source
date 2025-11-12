#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005000];
int s[10005000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+s[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(a[n]<a[1]+a[2]){
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	return 0;
}