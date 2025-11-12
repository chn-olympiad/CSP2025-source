#include<bits/stdc++.h>
using namespace std;
char c[10001][10001],r[10001][10001],x[10001],y[10001],a[10001],b[10001];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>c[i]>>r[i];
    }
    while(q--){
        int ans=0,chk=0,st=0,ed=0;
        cin>>x>>y;
        int l=min(strlen(x),strlen(y));
        for(int i=0;i<l;i++){
            if(x[i]!=y[i]){
                if(chk==0){
                    st=i;
                    chk=1;
                }else{
                    ed=i;
                }
            }
        }
        for(int i=st;i<=ed;i++){
            a[i-st]=x[i];
            b[i-st]=y[i];
        }
        for(int i=0;i<n;i++){
            if(a==c[i]&&b==r[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

