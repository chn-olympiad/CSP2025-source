#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r;
    cin>>c>>r;
    int a[10005];
    int f=c*r;
    int w,o;
    for(int i=0;i<=f-1;i++){
        cin>>a[i];//start at 1
    }
    w=a[0];
    for(int i=0;i<=f;i++){
            for(int j=0;j<=f;j++){
                if(a[i]<a[j]){
                    int t;
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
    int temp1=1;
    for(int i=f;i>=0;i--){
        if(a[i]==w){
            o=temp1;
        }
        else{
            temp1+=1;
        }
    }
    int c1,c2;
    c1=o/2;
    if(c1%2!=0){
       if(o/2==0){
            c2=r;
        }
        else{
            c2=o-r*c1;
        }
    }
    else{
       if(o/2==0){
            c2=1;
        }
        else{
            c2=o-r*cl+1;
        }
    }
    cout<<c1<<" "<<c2;
    return 0;
}
