#include <bits/stdc++.h>
using namespace std;
//freopen("seat.in","r",stdin);
//freopen("seat,out","w",stdout);
int main{
   	int n,m,i,j,s,c,r;
    char a[100]; 
	cin>>n>>m;
    for(i=1,i<=n*m,i++){
        cin>>a[i];
		}
    for(j=2,j<=n*m,j++){ 
        if(a[1]<a[j])
            s=j;
			}
    if(s%n!=0){
	    c=s/n+1;
    else{
        c=s/n;
		}
	}
    if(j%2=0){
        r=n-s%c;
    else{
        r=s%c;
		}
	}
   cout<<c<<r;
   return 0
}

