#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
int n,q,st,en;
string a[maxn],b[maxn],x,y;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    while(q--){
        cin>>x>>y;
        int ans=0;
        if(x.size()!=y.size()){
            cout<<0<<endl;
            continue;
        }
        int len=x.size();
        for(int i=0;i<len;i++){
            if(x[i]!=y[i]){
                st=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(x[i]!=y[i]){
                en=i;
                break;
            }
        }
        string str=x.substr(st,en-st+1);
        // cout<<"find\n";
        for(int i=1;i<=n;i++){
            if(a[i].find(str)<a[i].size()){
                // cout<<i<<" "<<a[i].find(str)<<endl;
                // cout<<a[i]<<" "<<str<<endl;
                if(x.find(a[i])<x.size()){
                    int tmp=x.find(a[i]);
                    if(y.substr(tmp,a[i].size())==b[i]){
                        ans++;
                    }
                }
            }

        }
        cout<<ans<<"\n";
    }

    return 0;
}