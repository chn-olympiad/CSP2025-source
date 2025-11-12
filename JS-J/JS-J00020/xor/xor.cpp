#include<bits/stdc++.h>
using namespace std;
/*
*/
const int N=5e5+10;
int a[N];
set<pair<int,int>>s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
                int f=0;
            for(int u=i;u<=i+j;u++){
                f^=a[u];
                if(f==k){
                    s.insert({u,i});
                }
            }
        }
    }
    long long h=0,b=-1;
    for(auto i:s){
        if(b==-1){
            b=i.first;
            h++;
        }else{
            if(i.second>b){
                b=i.first;
                h++;
            }
        }
    }
    cout<<h;
    return 0;
}
