#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,v,f,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    v=a[1],x=1,y=1,f=1;
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>0;i--){
	    if(v==a[i]) break;
	    if(y+f>n||y+f<1) f=-f,x++;
	    else y+=f;        
	}
	cout<<x<<" "<<y;
    return 0;
}
