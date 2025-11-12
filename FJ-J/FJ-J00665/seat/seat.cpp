#include<bits/stdc++.h>
using namespace std;
int a[110]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a,a+n*m);
    for(int i=1;i<=n*m;i++){
    	if(a[i]==x){
		    if(i%n==0){
			    if((i/n)%2==0) cout<<m<<" "<<1;
			    else cout<<m<<" "<<n;
		    }else{
			    if((i/n)%2==0) cout<<(i/n)+1<<" "<<i%n;
			    else cout<<(i/n)+1<<" "<<n-(i%n)+1;			
		    }
	    }
	}
	return 0;
}