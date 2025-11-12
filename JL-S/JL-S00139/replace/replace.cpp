#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        string t1,t2,tt;
        cin>>t1>>t2;
        tt=t1;
        int len=t1.size();
        for(int i=1;i<=n;i++){
            int l=a[i][1].size();
            for(int j=0;j<len-l+1;j++){
                for(int k=0;k<l;k++){
                    if(a[i][1][k]!=t1[j+k]){
                        goto Finish;
                    }
                }
                for(int k=0;k<l;k++){
                    tt[j+k]=a[i][2][k];
                }
                //cout<<tt<<"\n";
                if(tt==t2){
                    ans++;
                    break;
                }
                tt=t1;
                Finish :;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
