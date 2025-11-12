#include<bits/stdc++.h>
using namespace std;
string s1[200020],s2[200020],q1[200020],q2[200020];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>q1[i]>>q2[i];
        int cnt=0;
        for(int l=0;l<n;l++){
            for(int j=1;j<=n;j++){
                int z=s1[j].size();
                int r=l+z-1;
                bool f=true;
                for(int k=0;k<z;k++){
                    if(s1[j][k]!=q1[i][l+k]||s2[j][k]!=q2[i][l+k])f=false;
                }
                for(int m=0;m<q1[i].size();m++){
                    if(m>=l&&m<=r)continue;
                    if(q1[i][m]!=q2[i][m])f=false;
                }
                if(f)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
