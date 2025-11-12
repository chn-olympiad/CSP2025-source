#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int q,n,a[maxn];
string s;
string t;
string x;
string y;
int sum=0,ans=0,;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s>>t;
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
    }
    for(int j=1;j<=q;j++){
        for(int i=1;i<=n;i++){
            if(x[i]==y[i]){
                ans++;
            }
        }
        if(ans>=3) sum++;
        ans=0;
    }
    cout<<sum;
    return 0;
}


