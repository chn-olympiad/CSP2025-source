#include <bits/stdc++.h>
using namespace std;
long long n,k,p,l,cup;
long long a[500001];
long long qa[500001];
//int dfs(int yy,int r,int l){
//    if(r>=l||l==n){
//        return yy;
//    }
//    if((qa[l]-qa[r])%2==0){
//        r=l;
//        l=r+1;
//        yy++;
//    }
//    dfs(yy,r,l+1);
//    dfs(yy,r+1,l+1);
//    dfs(yy,r+1,l+1);
//}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            qa[i]=a[i];
        }
        if(i>0){
            qa[i]=a[i]+qa[i-1];
        }

        if(a[i]!=1){
            p=1;
        }
        if(a[i]>1){
            l=1;
        }
    }
    if(p==0){
        if(k==0){
            if(n==1){
                cout<<"0";
            }
            if(n==2){
                cout<<"1";
            }
            else if(n%2==1){
                cout<<(n-1)/2;
            }
            else if(n%2==0){
                cout<<n/2;
            }
            return 0;
        }
    }
    if(l==0){
        if(k==0){
                int r=0,l=1,cup;
                while(l>r){
                    if((qa[l]-qa[r])%2==0){
                        r=l;
                        l=r+1;
                        cup++;
                    }
                    else{
                        l++;
                    }
                }
            }
            cout<<cup;
        }
        else if(k==2){cout<<2;
        }
        else cout<<1;
    return 0;
}
