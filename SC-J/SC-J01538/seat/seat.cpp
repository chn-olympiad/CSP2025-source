#include<bits/stdc++.h>
using namespace std;
int m,n,a1;
int a[144],s[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=0;
	for(int c=1;c<=m;++c)
		for(int r=1;r<=n;++r){
			int w;cin>>w;
			a[++len]=w,s[c][r]=w;
		}
	a1=a[1];
	for(int j=0;j<n*m;++j)
		for(int i=2;i<=n*m;++i)
			if(a[i]>=a[i-1]){
				int p=a[i-1];
				a[i-1]=a[i];
				a[i]=p;
			}
	len=1;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;++j){
			s[i][j]=a[len];
			if(len%n!=0) ++len;
			else len=len+n+1;
		}
	}
	len=n+1;
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;--j){
			s[i][j]=a[len];
			if(len%n!=0) ++len;
			else len=len+n+1;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)
	    	if(s[i][j]==a1){
	    		cout<<i<<" "<<j;
	    		return 0;
			} 
	}		
	return 0;
}
