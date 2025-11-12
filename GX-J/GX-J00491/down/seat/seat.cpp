#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,p[10001];
    int a,i,t=0;
    cin>>n>>m;
    a=n*m;
    for(i=1;i<=a;i++){
    cin>>p[i];
    }
    int v=1,d=1;
    for(i=1;i<=a;i++){
		
    if(p[1]<p[i]){
    if(t==1){
		d-=1;
    if(d==n){
    t=0;
    v+=1;
    }
    }
    else{
		d+=1;
    if(d==n+1 && v!=m){
    v+=1;
    d-=1;
    t=1;
    }
    }
   }
}
    cout<<v<<","<<d;
    return 0;
}
