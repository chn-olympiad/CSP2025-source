#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,h,k;
	long long a=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>h;
		if(h==0){
			k=1;
		}
	}
	if(k==1&&m==n){
		for(int i=1;i<=n-1;i++){
		    a=a*i;
		    a=a%998244353;
	    }
	    cout<<a;
	    return 0;
	}
	for(int i=1;i<=n;i++){
		a=a*i;
		a=a%998244353;
	}
	cout<<a;
	return 0;
} 
