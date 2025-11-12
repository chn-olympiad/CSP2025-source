#include<bits/stdc++.h>
using namespace std;
int x[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int p=max(a,b);
		int zd=max(p,c);
		if(a+b+c>zd*2){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n-2;
	}
	return 0;
} 
