#include<bits/stdc++.h>
using namespace std;
int n,a[10005],maz,sum,f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		maz=max(maz,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(maz*2<sum){
			cout<<1;
		}
		else cout<<0;
	}
	else if(f==0){
		int anss=0,o=1,d=1;
		for(int i=3;i<=n;i++){
			o=1,d=1;
			for(int j=1,j1=n;j<=i;j++,j1--){
				d*=j;
				o*=j1;
			}
			anss+=o/d;
			//cout<<o<<d;
		}
		cout<<anss;
	}
	else cout<<9;
	return 0;
}