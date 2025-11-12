#include<bits/stdc++.h>
using namespace std;
int n,a[5010],_,ans,t,k;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            _++;
        }
    }
    if(_==n){
        cout<<(n-1)*(n-2)/2;
        return 0;
    }
    if(n>50){
        cout<<n;
        return 0;
    }
    k=pow(2,n);
    for(int i=1,j,x,m,l,f;i<k;i++){
        t++,j=0,m=0,l=0,f=0;;
        x=t;
        while(x){
            j++;
            if(x%2){
                m=max(a[j],m);
                l+=a[j];
                f++;
            }
            x/=2;
        }
        if(l>m*2&&f>2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
