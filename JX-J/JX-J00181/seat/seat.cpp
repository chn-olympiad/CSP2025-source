#include<bits/stdc++.h>

using namespace std;
int m,n,p,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    int s;
    int a[101];
    cin>>s;
    int r=s;
    for (int i=0;i<n*m-1;i++){
        cin>>s;
        a[s]++;
    }
    for (int i=100;i>=0;i--){
        if (i>r){
            if (a[i]!=0){
                p++;
            }
        }else{
            break;
        }
    }
    int l=p/n;
    if (p%n!=0){
        l++;
    }
    if (l%2!=0){
        if (p%n==0)
        {
            h=n;
        }else{
            h=p%n;
        }
    }else{
        h=n-(p%n);
    }
    cout<<l<<" "<<h;
    return 0;
}
