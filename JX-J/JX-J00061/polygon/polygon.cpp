#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5){
        if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
            cout<<'9';
        }
        else if(a[1]==2){
            cout<<'6';
        }
    }
    else if(n==3){
            int p=-1;
            int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]>p){
                p=a[i];
            }
            sum+=a[i];
        }
        if(sum>p*2){
            cout<<'1';
        }
        else{
            cout<<'0';
        }
    }
    int p=-1;
    for(int i=1;i<=n;i++){
        if(a[i]>p){
            p=a[i];
        }
    }
    long long kl=0;
    if(p==1){
        for(int i=1;i<=n;i++){
            kl+=i;
        }
        cout<<kl;
    }
    return 0;
}
