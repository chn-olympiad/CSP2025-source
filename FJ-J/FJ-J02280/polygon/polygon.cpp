#include<bits/stdc++.h>
using namespace std;

int n,s,maxa,c;
int a[5016];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa<=1){
		cout<<(n-2)%998244353;
		return 0;
	}
	if(s>2*maxa){
		c++;
	}
	cout<<c%998244353;
	return 0;
}
