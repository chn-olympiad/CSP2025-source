#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r,n,m,b=0,k=1;
    cin>>n>>m;
    int a[n*m],max=0;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    while(k!=0){
        for(int i=0;i<n*m;i++){
            if(max<a[i]){
                max=a[i];
            }
        }
        for(int i=0;i<n*m;i++){
            if(a[i]==max){
                if(i==0){
                    k=0;
                    break;
                }else{
                    a[i]=0;
                    max=0;
                    b++;
                    break;
                }
            }
        }
    }
    c=b/n+1;
    if(c%2!=0){
        r=b%n+1;
    }else{
        r=n-(b%n);
    }
    cout<<c<<" "<<r;
    return 0;
}
