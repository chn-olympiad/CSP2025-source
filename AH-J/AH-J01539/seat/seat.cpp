#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,b=1,d,c=0,r=1;
    cin>>n>>m;
    cin>>a;
    d=a;
    for(int i=1;i<n*m;i++){
        cin>>a;
        if(a>d){
            b++;
        }
    }
    for(int i=0;i<b;i++){
        if(r%2==1){
            c++;
            if(c==n+1){
                r++;
                c=n;
            }
        }
        else{
            c--;
            if(c==0){
                r++;
                c=1;
            }
        }
    }
    cout<<r<<" "<<c;
    return 0;
}
