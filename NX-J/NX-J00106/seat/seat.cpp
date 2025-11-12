#include<bits/stdc++.h>
using namespace std;
int a[10000];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,o,cs,h,s,pdd=1;
    cin>>n>>m;
    x=n*m;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    cs=a[1];
  //cout<<cs<<endl;
    for(int k=1;k<=x;k++){
        for(int g=1;g<=x;g++){
            if(a[g]<a[g+1]){
                o=a[g];
                a[g]=a[g+1];
                a[g+1]=o;
            }
        }
    }

    for(int p=1;p<=x;p++){
       if(cs==a[p]){
        o=p;
       }
    }
    h=1;
    s=1;

    for(int i=1;i<=1000;i++){
        if(o-n<=0){
            if(pdd==1){
                s=o;

            }
            else{
                s=n-o+1;

            }
            break;
        }
        else{
            o=o-n;
            h=h+1;
            if(pdd==1){
                pdd=0;
            }
            else if(pdd==0){
                pdd=1;
            }

        }
    }
    cout<<h<<" "<<s;
    return 0;
}
