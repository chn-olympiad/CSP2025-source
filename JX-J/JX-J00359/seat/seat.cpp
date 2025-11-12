#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1&&m==1){
        int a;
        cin>>a;
        cout<<1<<" "<<1;
    }
    else if(n==1){
        int a[m+1];
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        int x=1;
        int b[m+1];
        int r=a[1];
        while(x!=m){
            int k=0,f;
            for(int i=1;i<=m;i++){
                if(a[i]>=k){
                    k=a[i];
                    f=i;
                }
            }
            b[x]=k;
            a[f]=0;
            x++;
        }
        for(int i=1;i<=m;i++){
            if(b[i]==r) cout<<i<<" "<<1;
        }
    }
    else if(m==1){
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int x=1;
        int b[n+1];
        int r=a[1];
        while(x!=n){
            int k=0,f;
            for(int i=1;i<=n;i++){
                if(a[i]>=k){
                    k=a[i];
                    f=i;
                }
            }
            b[x]=k;
            a[f]=0;
            x++;
        }
        for(int i=1;i<=n;i++){
            if(b[i]==r) cout<<1<<" "<<i;
        }
    }
    else if(n<=2&&m<=2){
        int a[n*m+1];
        for(int i=1;i<=n*m;i++){
            cin>>a[i];
        }
        int x=1;
        int b[n*m+1];
        int r=a[1];
        while(x!=n*m){
            int k=0,f;
            for(int i=1;i<=n*m;i++){
                if(a[i]>=k){
                    k=a[i];
                    f=i;
                }
            }
            b[x]=k;
            a[f]=0;
            x++;
        }
        for(int i=1;i<=n*m;i++){
            if(b[i]==r){
                if(i<=2) cout<<1<<" "<<i;
                else if(i==3) cout<<2<<" "<<2;
                else cout<<2<<" "<<1;
            }
        }
    }
    else if(m<=2){
        int a[n*m+1];
        for(int i=1;i<=n*m;i++){
            cin>>a[i];
        }
        int x=1;
        int b[n*m+1];
        int r=a[1];
        while(x!=n*m){
            int k=0,f;
            for(int i=1;i<=n*m;i++){
                if(a[i]>=k){
                    k=a[i];
                    f=i;
                }
            }
            b[x]=k;
            a[f]=0;
            x++;
        }
        for(int i=1;i<=n*m;i++){
            if(b[i]==r){
                if(i<=n) cout<<1<<" "<<i;
                else cout<<2<<" "<<n*m-i+1;
            }
        }
    }
    else if(n<=2){
        int a[n*m+1];
        for(int i=1;i<=n*m;i++){
            cin>>a[i];
        }
        int x=1;
        int b[n*m+1];
        int r=a[1];
        while(x!=n*m){
            int k=0,f;
            for(int i=1;i<=n*m;i++){
                if(a[i]>=k){
                    k=a[i];
                    f=i;
                }
            }
            b[x]=k;
            a[f]=0;
            x++;
        }
        for(int i=1;i<=n*m;i++){
            if(b[i]==r){
                if(i%4==2&&i%4==1) cout<<i/2<<" "<<i%4;
                else if(i%4==3) cout<<(i+1)/2<<" "<<2;
                else cout<<i/2<<" "<<1;
            }
        }
    }
    return 0;
}
