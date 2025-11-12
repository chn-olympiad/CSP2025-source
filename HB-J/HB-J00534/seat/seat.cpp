#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x[10001]={0};
    cin>>x[0];
    int R=x[0];
    for(int i=1;i<n*m;i++){
        cin>>x[i];
    }
    int max1=0,maxwei=0;
    int y[10001]={0};
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(x[j]>max1){
                max1=x[j];
                maxwei=j;
            }
        }
        y[i]=max1;
        x[maxwei]=0;
        max1=0;
    }
    int numwei=0;
    for(int i=0;i<n*m;i++){
        if(y[i]==R){
            numwei=1+i;
            break;
        }
    }
    int c,r;
    if(numwei%n==0){
        c=numwei/n;
        r=n;
        cout<<c<<" "<<r;
    }else{
        c=numwei/n+1;
        if(c%2==1){
            r=numwei%n;
        }else{
            r=n-numwei%n+1;
        }
        cout<<c<<" "<<r;
    }
    return 0;

}

