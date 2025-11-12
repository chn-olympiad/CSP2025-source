#include<bits/stdc++.h>
using namespace std;
string a[100005],b[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1; i<=q; i++){
        string qa,qb;
        cin>>qa>>qb;
        int l,r,v=1;
        for(int j=0; j<qa.size(); j++){
            if(qa[j]!=qb[j]&&v==0){
                l=j;
                v=1;
            }if(qa[j]!=qb[j]){
                r=j;
            }
        }
        int ans=0;
        for(int j=1; j<=n; j++){
            if(qa.size()<a[j].size()) continue;
            for(int k=0; k<qa.size()-a[j].size(); k++){
                if(k<=l&&k+a[j].size()>r||v==0){
                    int fl=0;
                    for(int p=k; p<k+a[j].size(); p++){
                        if(a[j][p-k]!=qa[p]||b[j][p-k]!=qb[p]){
                            fl=1;
                            break;
                        }
                    }
                    if(fl==0){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}