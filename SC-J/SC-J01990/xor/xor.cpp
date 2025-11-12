#include<bits/stdc++.h>
using namespace std;
long long k,x,n,a[500010],c,ma,i,j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		x=a[i];
		c=0;
		for(j=i+1;j<=n;j++){
			if(x==k){
				c++;
				x=a[j];
			} 
			else x=a[j]^x;
		}
		if(x==k){
			c++;
		}
		ma=max(ma,c);
	}
	cout<<ma;
	return 0;	
}