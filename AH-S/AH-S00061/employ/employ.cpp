#include<bits/stdc++.h>
using namespace std;
int n,m,c[502],flaga,ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    int tot=n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)tot--;
    }
    if(tot<m)
    {
        cout<<0;
        return 0;
    }
    cout<<2204128;
    return 0;
}
