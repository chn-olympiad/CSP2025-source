#include<bits/stdc++.h>
using namespace std;
int c1[10010][7];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int ts=1;ts<=t;ts++){
        int n,m=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>c1[i][j];
            }
            m+=max(c1[i][3],max(c1[i][1],c1[i][2]));
        }
        cout<<m<<endl;
    }

    return 0;
}
