#include<bits/stdc++.h>
using namespace std;
int n[10000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s,m;
    cin>>s>>m;
    for(int i=0;i<=s;i++){
        for(int i=0;i<=m;i++){
            for(int j=1;j<=m;j++){
                cin>>n[i];
            }
        }


    }
    cout<<n;
    return 0;
}
