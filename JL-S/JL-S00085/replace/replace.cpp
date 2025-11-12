#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string a[n],b[n],c,d;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        bool sg=0;
        int l,r;
        cin>>c>>d;
        if(c.size()!=d.size()){cout<<0<<endl; continue;}
        for(int j=0;j<c.size();j++){
            if(sg==0&&c[j]!=d[j]) sg=1,l=j-1;
            if(c[j]==d[j]) r=j;
        }
        if(c[c.size()-1]!=d[d.size()-1]) r=c.size();
        int ans=0;
        for(int j=0;j<n;j++){
            int p=c.size()-a[j].size();
            for(int k=r-a[j].size();k<=min(p,l+1);k++){
                bool flag=1;
                for(int g=k;g<k+a[j].size();g++) if(c[g]!=a[j][g-k]||d[g]!=b[j][g-k]){flag=0; break;}
                if(flag==1){ans++; break;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
