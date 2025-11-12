#include <bits/stdc++.h>
using namespace std;
int n,m,a1,a[1000],r=1,c=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    for(int i=0;i<n*m-1;i++){
        cin>>a[i];
    }
    for(int j=0;j<n*m;j++){
        if(a1<a[j] && r<n){
            r++;
        }else   if(a1<a[j] && r+1>n && c%2!=0){
            r=n;
            c++;
        }else if(a1<a[j] && r<n && c%2==0){
            r--;
        }else if(a1<a[j] && r-1<0 && c%2==0){
            r=1;
            c++;
        }
    }
    cout<<c<<' '<<r;
	return 0;
}
