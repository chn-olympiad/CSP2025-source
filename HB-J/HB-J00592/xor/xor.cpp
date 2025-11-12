#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,x[500005],ans=0;
struct xy{
    int x;
    int y;
}b[25005];
int xr(int a,int b){
    if(a%2==b%2){
        return abs(a-b);
    }
    if(a%2!=b%2){
        return a+b;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=xr(a[i],x[i-1]);
        if(a[i]==k){
            b[ans].x=i;
            b[ans].y=i;
            ans++;
        }
    }
    for(int i=2;i<n;i++){
        for(int q=i;q<=n;q++){
            int s=q-i;
            int an=0;
            if(xr(x[q],x[s])==k){
                for(int l=0;l<=ans;l++){
                    if(s+1<=b[l].y&&q>=b[l].x){
                        an=1;
                    }
                }
                if(an!=1){
                    b[ans].x=s+1;
                    b[ans].y=q;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
