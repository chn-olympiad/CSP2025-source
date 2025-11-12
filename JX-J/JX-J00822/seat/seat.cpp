#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m]={0};
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int R=a[0];
    int temp[n*m]={0};
    while(true){
        bool b=false;
        for(int i=0;i<n*m;i++){
            if(a[i]<a[i+1]){
                temp[i]=a[i+1];
                temp[i+1]=a[i];
                i++;
            }
            else{
                temp[i]=a[i];
            }
        }
        for(int i=0;i<n*m;i++){
           if(a[i]==temp[i]{
                b=true;
           }
           else{
                a[i]=temp[i];
                b=false;
           }
        }
        if(b) break;
    }
    int c,r,n=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                c=i;
                r=j;
                if(a[n]==R){
                    cout<<c<<" "<<r;
                    return 0;
                }
                else{
                    n++;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                c=i;
                r=j;
                if(a[n]==R){
                    cout<<c<<" "<<r;
                    return 0;
                }
                else{
                    n++;
                }
            }
        }
    }

    return 0;

}

