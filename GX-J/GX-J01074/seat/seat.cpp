#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,z,x,s;
    cin>>n>>m;
    s=n*m;
    int a[s];
    for(int i=0;i<s;i++){
        cin>>a[i];
        z=a[1];
	}
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
            a[i]=a[j];
            a[j]=a[i];
            }
        }
        if(a[i]==z)
            x=i;
    }
    int l,h;
    if(x>n){
        l=x/n;
        h=x%n;
        if(l%2==0){
            h=n-h;
        }
        else if(l%2!=0){
                 h=h;
        }
    }
    cout<<h<<" "<<l;
    return 0;
}
