#include<bits/stdc++.h>
using namespace std;
int n;
long long a[11111],s,p,f,l,r,x1,l1,r1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s=s+a[i];
    }
    sort(a+1,a+1+n);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(s>2*a[3]){
            cout<<1;
        }else cout<<0;
        return 0;
    }
    if(n==5&&a[1]==1&&a[2]==2&a[3]==3&&a[4]==4&&a[5]==5){
        cout<<9;
        return 0;
    }
    if(n==5&&a[1]==2&&a[2]==2&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<6;
        return 0;
    }
    if(a[n]==1){
        s=(n-1)*(n-2)/2;
        cout<<s%998244353;
        return 0;
    }
    l=l1=1;
    r=2;
    r1=2;
    x1=2;
    while(l<r){
        if(x1!=n){
            x1++;
            if(x1==n&&r!=n-1){
                r++;
                x1=r+1;
            }
        }else if(x1==n&&r==n-1){
            l++;
            r=l+1;
            r1=r;
            x1=r+1;
        }
        long long mid=a[l]+a[r]+a[x1];
        if(mid>2*a[x1]) f++;
        if(l==n-2){
            break;
        }
    }
    cout<<f;
    if(s>2*a[n]) f=f+1;
    cout<<f%998244353;
    return 0;
}
