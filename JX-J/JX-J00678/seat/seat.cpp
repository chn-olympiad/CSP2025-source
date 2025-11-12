#include<bits/stdc++.h>

using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,sum=0,h,l,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            x=a[i];
        }
        else{
            if(a[i]>x){
                sum++;
            }
        }
    }
    sum+=1;
    l=sum/n;
    r=sum%n;
    if(r==0){
        l--;
        r=n;
    }
    if(l%2==0){
        cout<<l+1<<' '<<r;
    }
    else{
        cout<<l+1<<' '<<m-r+1;
    }
    return 0;
}
