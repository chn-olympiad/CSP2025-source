#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a=0,b,c=0,d;
	cin>>n;
	int m[n+1];
	for(int i=1;i<=n;i++){
		cin>>m[i];
		a=a+m[i];
	}
	
	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++){
			b=a;
			c=0;
			for(int k=0;k<j;k++){
				b=b-m[k];
			}
			for(int k=0;k<n;k++){
				if(k!=j&&c<m[k]){
					c=m[k];
				}
			}
			if(b>2*c){
				d+=1;
			}
		}
	}
	cout<<d;
	return 0;
}
