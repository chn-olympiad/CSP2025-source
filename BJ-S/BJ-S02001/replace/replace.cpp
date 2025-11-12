#include <bits/stdc++.h>

using namespace std;
int n,q,ans;
string ss[200005],se[200005];
string st,et,gcz;
bool behave(string sml,string big,int xb){
    for(int i=1;i<=sml.size();i++){
        if(big[xb+i]!=sml[i-1])return 0;
    }
    return 1;
}
string strong(string ww,int rp,int k){
    for(int i=1;i<=n;i++){
        ww[k+i]=se[rp][i-1];
    }
    return ww;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>ss[i]>>se[i];
    }
    while(q--){
        ans=0;
        cin>>st>>et;
        for(int i=0;i<st.size();i++){
            for(int j=1;j<=n;j++){
                if(behave(ss[j],st,i)){
                    if(strong(st,j,i)==et){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}