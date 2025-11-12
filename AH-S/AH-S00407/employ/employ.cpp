#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,k=0;
    cin>>n>>m;
    char s[n];
    char c[n];
    char p[n];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        cin>>c[i];
        cin>>p[i];
        if(s[i]==0){
            break;
        }else if(s[i]==1){
            k++;
        }
    }if(k>=m){
        cout<<k;
    }
    return 0;
}
