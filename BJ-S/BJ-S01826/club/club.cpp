#include<bits/stdc++.h>
using namespace std;
long long t,n,a[5][100100],b[5],c[100100];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        long long x=0,ans=0;
        for(long long i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            x=max(max(a[1][i],a[2][i]),a[3][i]);
            ans+=x;
            if(a[1][i]==x){
                b[1]++;
            }else if(a[2][i]==x){
                b[2]++;
            }else{
                b[3]++;
            }
        }
        if(b[2]>b[1] and b[2]>b[3]){
            swap(b[1],b[2]);
            swap(a[1],a[2]);
        }else if(b[3]>b[1] and b[3]>b[2]){
            swap(b[1],b[3]);
            swap(a[1],a[3]);
        }
        if(b[1]<=n/2){
            cout<<ans<<endl;
        }else{
            for(long long i=1;i<=n;i++){
                c[i]=a[1][i]-max(a[2][i],a[3][i]);
                if(c[i]<0){
                    c[i]=LONG_LONG_MAX;
                }
            }
            sort(c+1,c+n+1);
            for(long long i=1;i<=b[1]-n/2;i++){
                ans-=c[i];
                //cout<<c[i]<<endl;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
