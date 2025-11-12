#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long i,a[100010],d,z,ans,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    ans=1;
    for(i=2;i<=n*m;i++){
	    cin>>a[i];	
	    if(a[i]>a[1]){
		    ans++;	
		}
	}
	if(ans%n==0){
		x=ans/n;
		if(x%2==0){
		    y=1;	
		}else{
			y=n;
		}
	}else{
		x=ans/n+1;
		d=ans%n;
		if(x%2==0){
		    y=n-d+1;	
		}else{
			y=d;
		}
	}
	cout<<x<<" "<<y<<endl;
    return 0;
}
