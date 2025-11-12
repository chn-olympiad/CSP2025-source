#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s=0,z=-1e9;
int main(){
	//freopen("polygon","r",stdin);
	//freopen("polygon","w",stdout);
	cin>>n;
	if(n=3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s=a[i]+s;
			z=max(a[i],z);
	
		}
		if((s-z)>z){
			cout<<1;
		}
		else cout<<0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	return 0;
}
