
#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n,ma=-1;
    cin>>n;
    if(n<3)cout<<0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(ma<=1){
        if(n>=3)cout<<(1<<n)-1-n-n*(n-1)/2;
        else cout<<0;
        return 0;
    }
    int c=0;
    int m=1<<n;
    for(int i=0;i<m;i++){
        int sm=0,mx=-1,ct=0,j=1;
        int k=i;
        while(k!=0){

            int f=k%2;

            k/=2;
            if(f==1){
                ct++;
                sm+=a[j];
                mx=max(mx,a[j]);
            }
            j++;
        }
        if((ct>=3)&&(sm>2*mx)){
        c++;
        c%=998244353;
        }
    }
    cout<<c;
    return 0;
}


