#include<bits/stdc++.h>
using namespace std;
int n,q,ans,nsze,tsze,flag,szes1[200010],szes2[200010],szet1[200010],szet2[200010];
string tmp,s1[200010],s2[200010],t1[200010],t2[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i],getchar(),cin>>s2[i],getchar(),
        szes1[i]=s1[i].size(),szes2[i]=s2[i].size(),nsze+=szes1[i]+szes2[i];
    for(int i=1;i<=q;i++)
        cin>>t1[i],getchar(),cin>>t2[i],getchar(),
        szet1[i]=t1[i].size(),szet2[i]=t2[i].size(),tsze+=szet1[i]+szet2[i];
    // for(int i=1;i<=n;i++)
        // cout<<s1[i]<<' '<<s2[i]<<'\n';
    // for(int i=1;i<=q;i++)
        // cout<<t1[i]<<' '<<t2[i]<<'\n';
    if(n*q>5e8){
        while(q--) cout<<"0\n";
        return 0;
    }
    for(int qq=1;qq<=q;qq++){
        ans=0;
        for(int i=0;i<szet1[qq];i++)
            tmp[i]=t1[qq][i];
        for(int i=0;i<szet1[qq];i++){
            for(int j=1;j<=n;j++){
                if(i+szes1[j]-1<=szet1[qq]){
                    flag=1;
                    for(int k=0;k<szes1[j];k++)
                        if(t1[qq][i+k]!=s1[j][k]){flag=0;break;}
                    if(!flag) continue;
                    for(int k=0;k<szes1[j];k++)
                        t1[qq][i+k]=s2[j][k];
                    // cout<<i<<' '<<j<<'\n';
                    flag=(t1[qq]==t2[qq]);
                    for(int ii=0;ii<szet1[qq];ii++)
                        t1[qq][ii]=tmp[ii];
                    ans+=flag;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}