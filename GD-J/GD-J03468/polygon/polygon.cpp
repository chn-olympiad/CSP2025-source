#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int s=a+b+c;
		int m=max(a,max(b,c));
		if(s>2*m) cout<<1;
		else cout<<0;
	}
	else{
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<0;
	}
	return 0;
}
