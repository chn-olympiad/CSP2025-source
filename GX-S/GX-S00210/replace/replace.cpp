#include<bits/stdc++.h>
#include<istream>
int n,q;
char a[1000005][1000005],b[100005][100005];
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int i1=1;i1<=2;i1++){
            cin>>a[i][i1];
        }
    }
    for(int j=1;j<=q;j++){
        for(int j1=1;j1<=2;j1++){
            cin>>b[j][j1];
        }
    }
    freopen("replace.out","w",stdout);
    return 0;
}
