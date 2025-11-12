#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    while(q--){
        string x,y;
        int ans=0;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            int t=(int)x.find(a[i]);
            if(t!=-1){
                string s=x;
                for(int j=0;j<a[i].length();j++){
                    s[j+t]=b[i][j];
                }
                //cout<<s<<"\n";
                if(s==y){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
