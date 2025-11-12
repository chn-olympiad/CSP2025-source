#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sum=n*m;
    int ans=a[1];
    int l,r;
    int x,y;
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
            //cout<<a[i]<<endl;
        if(a[i]==ans){
            x=i;
        }
    }
    x=sum-(x-1);
    //cout<<x<<endl;
    if(x<=n){
        l=1;r=x;
        cout<<l<<" "<<r<<endl;
        return 0;
    }
    for(int i=1;i<=sum;i++){
        if(x>n){
            x-=n;
            r=sum-l*l-l-m+n;
            l++;
        }
    }
    if(l%2==0){
        r=x;
        l+=1;
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}
