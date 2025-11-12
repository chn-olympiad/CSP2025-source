#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[100005],b=1,c,d;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1]){
			b++;
		}
	}
	c=b/n;
	d=b%n;
	if(d>0){
		c++;
	}
	cout<<c<<" ";
	if(d>0){
	    if(c%2==0){
		    cout<<n-d+1;
    	}else{
    		cout<<d;
    	}
	}else{
		if(c%2==0){
		    cout<<1;
    	}else{
    		cout<<n;
    	}
	}
	return 0;
} 
