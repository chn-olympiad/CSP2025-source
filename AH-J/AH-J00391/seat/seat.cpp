#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],x,s,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i; break;
	    }
    }
    if(s%n==0)c=s/n; 
    else c=s/n+1;
    if(c%2==1){
		if(s%n==0)r=n;
		else r=s%n;
    }
    else{
		if(s%n==0)r=1;
		else r=n-m%n;
	} 
    cout<<c<<" "<<r;
	return 0;
}

