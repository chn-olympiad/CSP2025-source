#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int b[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=0;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            s++;
        }
    }
    s=s+1;
    int h,l;
    l=s/n;
    if(s%n!=0){
        l++;
    }
    if(l%2==1){
        if(s%n==0){
            h=n;
        }else{
            h=s%n;
        }

    }else{
        if(s%n==0){
            h=1;
        }else{
            h=n-(s%n)+1;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
