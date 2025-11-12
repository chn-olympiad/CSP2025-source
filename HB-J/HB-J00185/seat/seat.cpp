#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[105],ans,num;
    cin>>n>>m;
    int f=n*m;
    for(int i=0;i<f;i++) cin>>a[i];
    ans=a[0];
    sort(a,a+f);
    for(int i=f-1;i>=0;i--)
        if(a[i]==ans){
            num=f-i;
            break;
        }
    int l=num/n,r=num%n;
    if(r!=0) l++;
    if(r==0&&l%2==0) r=1;
    else if(r==0&&l%2==1) r=n;
    else if(r!=0&&l%2==0) r=n+1-r;
    cout<<l<<" "<<r;
    return 0;
}
