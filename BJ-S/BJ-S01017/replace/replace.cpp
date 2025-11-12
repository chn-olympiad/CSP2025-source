#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string a[N][2],b[N][2];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=m;i++){
        string x,y;
        cin>>x>>y;
        cnt=0;
        int l=-1,r=-1;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i]){
                if(l==-1)l=i;
                r=i;
            }
        }
        string t=x.substr(l,r-l+1),u=y.substr(l,r-l+1);
        for(int i=1;i<=n;i++){
            if(a[i][1].find(t)==a[i][2].find(u)&&a[i][1].find(t)!=-1)cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
