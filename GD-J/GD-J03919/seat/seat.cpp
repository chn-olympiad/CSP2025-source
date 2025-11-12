#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.in","w",stdin);
    int n,m,x,y,s,ns,ms;
    cin>>n>>m;
    int a[n*m];
    cin>>a[0];
    int num=a[0];
    for (int i=1;i<n*m;i++){
        cin>>a[i];
        if (a[0]<a[i]){
        	s++;
		}
    }
    int N=2*n;
    y=s%N;
    x=(s-y)/N;
    if (y==0){
        ns=1;
        ms=x*2;
    }else if (y<=n){
        ns=y;
        ms=x*2+1;
    }else{
        ns=2*n-y+1;
        ms=x*2+2;
    }
    cout<<ns<<ms;
	return 0;
}
