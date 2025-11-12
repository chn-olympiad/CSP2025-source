#include<bits/stdc++.h>
using namespace std;
int n,m,b,v[100001],a,s,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		a+=v[i];
	}if(n<=3){
		s=max(v[1],max(v[2],v[3]));
		if(a>s&&n>=3){
			cout<<1%998244353;
		}else{
			cout<<0%998244353;
		}return 0;
	}else{
		cout<<1;
	}
	return 0;
}
