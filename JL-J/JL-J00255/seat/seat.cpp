#include <bits/stdc++.h>
using namespace std;
int s[1100],xu;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    int t=s[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(s[i]<s[j])
            {
                swap(s[i],s[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(s[i]==t){
            xu=i;
            break;
        }
    }
    int l=ceil(double(xu)/double(n));
    int u=xu%n;
    if(l%2==0){
        cout<<l<<" "<<n-u+1;
    }
    else{
        if(u==0)
            cout<<l<<" "<<n;
        else{
            cout<<l<<" "<<u;
        }
    }
    return 0;
}
