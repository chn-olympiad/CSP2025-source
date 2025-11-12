#include<bits/stdc++.h>
using namespace std;
int a[101],m,n,i,j,r,p,l,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n*m;i++)
        cin>>a[i];
    r=a[0];
    sort(a,a+n*m);
    for(i=n*m-1;i>=0;i--)
        if(a[i]==r){
            p=n*m-i;
            break;
        }
    if(p%(n+n)==0){
        l=p/(n+n)*2;
        h=1;
        cout<<l<<" "<<h;
        return 0;
    }
    else{
        if(p%n==0){
            if((p/n)%2!=0){
                l=p/n;
                h=n;
                cout<<l<<" "<<h;
                return 0;
            }
            else if((p/n)%2==0){
                l=p/n;
                h=1;
                cout<<l<<" "<<h;
                return 0;
            }
        }
        else{
            l=p/n+1;
            if(l%2!=0){
                h=p%n;
                cout<<l<<" "<<h;
                return 0;
            }
            else{
                h=n-p%n+1;
                cout<<l<<" "<<h;
                return 0;
            }
        }
    }
    return 0;
}
