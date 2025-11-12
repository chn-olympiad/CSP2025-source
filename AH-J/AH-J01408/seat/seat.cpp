#include<bits/stdc++.h>
using namespace std;
struct p{
     int fp;
     bool isR=0;
}a[1000];
bool cmp(p x,p y){
     return x.fp>y.fp;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,ix;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i].fp;
    a[1].isR=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i].isR){
           ix=i;
           break;
        }
    int f=ix/n+1;
    if(ix%n==0)f--;
    cout<<f<<" ";
    int x=ix%n;
    if(x==0){
		if(f%2)cout<<n;
		else cout<<1;
	}
    else {
		if(f%2)cout<<x;
		else cout<<n-x;
	}
    return 0;
}
