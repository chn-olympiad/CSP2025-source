#include <bits/stdc++.h>

using namespace std;
int n,m,a[505],b[505],ans=0,d[505];
string e;
void pai(int n1){
    if(n1==n){
        int c=0,f=0;
        for(int i=0;i<n;i++){
            if(a[d[i]]>c&&e[i]=='1'){
                f++;
            }
            else{
                c++;
            }
        }
        if(f>=m){
            ans++;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            d[n1]=i;
            b[i]=1;
            pai(n1+1);
            b[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>e;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    pai(0);
    cout<<ans;

    return 0;
}
