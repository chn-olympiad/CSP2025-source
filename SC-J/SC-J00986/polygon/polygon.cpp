#include<bits/stdc++.h>
using namespace std;
int sum=0,s,mx,zz;
int n,bb,mn=-1e9;
int j;
int a[100010];
int f(int x){
	sum+=a[x];
	for(int i=x+1;i<=n-s;i++){
		if(s==j){
			return sum;
		}
		mx=max(i,mx);
		f(i);
		s++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bb+=a[i];
		if(n==3){	
			mn=max(a[i],mn);
		}
	}
	if(n==3){
		if(bb>2*mn){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}else if(bb==n){
		cout<<(n-2)*n*(n-1)/2;
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(j=1;j<=n-k;j++){
			sum=0;
		    s=1;
		    mx=-1e9; 
		    if(f(k)>2*mx){
		    	zz++;
			}
		}
	}
    cout<<zz%998244353+a[1];
	return 0;
} 