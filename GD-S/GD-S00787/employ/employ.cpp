#include<bits/stdc++.h>
using namespace std;
int m,n,b[501],c,d,e=1,f,g[501];
char a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];	
	for(int i=1;i<=n;i++){
		cin>>b[i];
		g[i]=b[i];
	}
	for(int i=2;i<=n;i++)e=e*i;
	while(e>0){
		c=m;
		for(int i=1;i<=n;i++){
		    if(a[i]=='1' && b[i]>0)c--;
		    if(a[i]=='0'){
			    for(int j=i;j<=n;j++)b[j]--;			
	        }
	        if(c==0){	        	
	        	d=d%998244353+1;	        	
	        	break;
			}
			d=d%998244353;
		}
		for(int i=1;i<=n;i++)b[i]=g[i];
		f=b[n];
		for(int i=n-1;i>=1;i--)b[i+1]=b[i];
		b[1]=f;
		e--;
	}
	cout<<d%998244353;	
	return 0;
}
