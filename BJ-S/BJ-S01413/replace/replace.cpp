#include <bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int pl1[200005],pl2[200005];
int main(){
    ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for (int j=0;j<s1[i].size();j++){
            if (s1[i][j]=='b'){
                pl1[i]=j;
                break;
            }
        }
        for (int j=0;j<s2[i].size();j++){
            if (s2[i][j]=='b'){
                pl2[i]=j;
                break;
            }
        }
    }
    if (q==1){
        long long ans=0;
        string q1,q2;
        cin>>q1>>q2;
        for (int i=1;i<=n;i++){
            int cntc=0;
            bool flag11=0,flag22=0;
            for (int j=0;j<q1.size();j++){
                if (s1[i][cntc]==q1[j]){
                    cntc++;
                }
                else{
                    cntc=0;
                }
                if (cntc==s1[i].size()){
                    flag11=1;
                    break;
                }
            }
            cntc=0;
            for (int j=0;j<q2.size();j++){
                if (s2[i][cntc]==q2[j]){
                    cntc++;
                }
                else{
                    cntc=0;
                }
                if (cntc==s2[i].size()){
                    flag22=1;
                    break;
                }
            }
            if (flag11&&flag22){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    else{
        while(q--){
            string q1,q2;
            cin>>q1>>q2;
            int q1pl,q2pl;
            for(int i=0;i<q1.size();i++){
                if (q1[i]=='b'){
                    q1pl=i;
                }
            }
            for (int i=0;i<q2.size();i++){
                if (q2[i]=='b'){
                    q2pl=i;
                }
            }
            int plcha=q1pl-q2pl;
            long long ans=0;
            for(int i=1;i<=n;i++){
                if (pl1[i]-pl2[i]==plcha&&pl1[i]<=q1pl&&(q1pl-pl1[i])+s1[i].size()<=q1.size()){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}