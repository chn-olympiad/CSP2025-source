#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int n,m;
int f(int n){
    for(int i=0;i<n*m;i++){
        if(a[i]==n){
            return i;
        }
    }
    return 0x3f3f3f3f3f;
}
void r(){
    int c[100005];
    for(int i=0,j=m*n-1;i<m*n&&j>=0;i++,j--){
        c[j]=a[i];
    }
    for(int i=0;i<n*m;i++){
        a[i]=c[i];
    }
    return;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int g=a[0];
    sort(a,a+n*m);
    r();
    int d=f(g)+1;
    //for(int i=0;i<n*m;i++){
      //  cout<<a[i];
    //}
    if(d/n==1) {
    	cout<<1<<' '<<n;
    	return 0;
	}
    if((d/n+1)%2==1){
        if(d%n==0){
            cout<<d/n+1<<' '<<1;
        }
        else{
            cout<<d/n+1<<' '<<d%n;
        }
    }
    else{
        if(d%n==0){
            cout<<d/n+1<<' '<<n;
        }
        else{
            cout<<d/n+1<<' '<<n-(d%n)+1;
        }
    }
    return 0;
}
