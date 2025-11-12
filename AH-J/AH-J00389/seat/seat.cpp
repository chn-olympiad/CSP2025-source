#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,x,ct=1,f,l=1,r=1;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    while(a[ct]!=x){
        if(f==0)
            l++;
        else if(f==1)
            l--;
        ct++;
        if(a[ct]==x)
            break;
        if(l==n){
            r++;
            f=1;
            ct++;
        }else if(l==1){
            r++;
            f=0;
            ct++;
        }
    }
    cout<<r<<" "<<l;
    return 0;
}
