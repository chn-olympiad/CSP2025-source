#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,b[1000000],a[1000000],s,c,ma=INT_MIN,f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(f==0){
		if(n<=2)cout<<0;
		else if(n==3){
			if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))s++;
			cout<<s;
		}
		else{
			for(i=4;i<=n;i++){
				s++;
				c=c+s;
			}
			cout<<5*c;
		}
		
		return 0;
	}
	if(n<=2)cout<<0;
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))s++;
		cout<<s;
	}
	else{
		for(i=1;i<=n-2;i++){
			for(j=i+2;j<=n;j++){
				ma=INT_MIN;
				s=0;
				for(k=i;k<=j;k++){
					s=s+a[k];
					ma=max(ma,a[k]);
				}
				if(s>2*ma)c++;
			}
		}
		cout<<c%998244353;	
	}
}
