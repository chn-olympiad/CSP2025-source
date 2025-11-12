#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y;
    cin>>x>>y;
    int n=x*y;
    int a[x*y+5];
    for(int i=1;i<=n;i++)cin>>a[i];
    int r=a[1];
    sort(a+1,a+1+n);
    if(a[n]==r){
        cout<<1<<" "<<1;
        return 0;
    }if(x==1){
        int t=1;
        for(int i=n;i>=1;i--,t++)
            if(a[i]==r){
                cout<<t<<" 1";
                return 0;
            }
    }if(y==1){
        int t=1;
        for(int i=n;i>=1;i--,t++)
            if(a[i]==r){
                cout<<"1 "<<t;
                return 0;
            }
    }
    int x1=1,y1=1,x2=2,y2=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]==r){
            cout<<y2<<" "<<x2;
            return 0;
        }
        if(x2==x){
            if(x2==x1+1){y1=y2;x1=x2;y2++;}
            else {x1=x2;x2--;}
        }else if(x2==1){
            if(x2==x1-1){y1=y2;x1=x2;y2++;}
            else {x1=x2;x2++;}
        }else if(x2==x1+1){x1=x2;x2++;}
        else {x1=x2;x2--;}
    }
    return 0;
}
