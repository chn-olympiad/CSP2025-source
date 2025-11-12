#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c=a*b;
    int p=0;
    int y[c];
    for(int i=1;i<=c;i++){
        cin>>y[i-1];
    }
    for(int i=1;i<=c;i++){
        if(y[0]<y[i-1]){
            p++;
            cout<<y[i-1]<<1;
        }
    }
    p++;
    cout<<p<<endl;
    int j;
    if(p%a==0){
        cout<<p/a<<" ";
        j=p/a;
    }else{
        cout<<p/a+1<<" ";
        j=p/a+1;
    }

    if(j%2==1){
        if((p+a*(j-1))%a==0){
             cout<<p+a*(j-1);
        }
        else{
              cout<<(p+a*(j-1))%a;
        }


    }else{
         if((a-p+1+a*(j-1))%a==0){
             cout<<a-p+1+a*(j-1);
        }
        else{
              cout<<(a-p+1+a*(j-1))%a;
        }

    }
}
