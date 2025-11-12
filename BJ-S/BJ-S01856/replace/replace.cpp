#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,dp[1000005],q1[1000005],q2[1000005],ls[1000005];
string s1[200005],s2[200005],l1,l2;
map<string,string> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        ls[i]=s1[i].size();
        mp[s1[i]]=s2[i];
    }
    while(q--){
        cin>>l1>>l2;
        ll l1s=l1.size(),l2s=l2.size();
        l1=' '+l1;
        l2=' '+l2;
        if(l1s!=l2s){
            cout<<0<<endl;
            continue;
        }
        ll op=1,ans=0;
        for(int i=1;i<=l1s;i++){
            if(l1[i]==l2[i]&&op==1){
                q1[i]=1;
            }else{
                op=0;
                q1[i]=0;
            }
            //cout<<q1[i];
        }
        //cout<<endl;
        op=1;
        for(int i=l1s;i>=1;i--){
            if(l1[i]==l2[i]&&op==1){
                q2[i]=1;
            }else{
                op=0;
                q2[i]=0;
            }
            //cout<<q2[i];
        }
        q1[0]=1;
        dp[0]=1;
        q2[l1s+1]=1;
        for(int i=1;i<=l1s;i++){
            for(int j=1;j<=n;j++){
                if(q1[i-1]&&q2[i+ls[j]]&&i+ls[j]-1<=l1s){
                    string x="",y="";
                    for(int k=i;k<=i+ls[j]-1;k++){
                        x+=l1[k];
                        //cout<<l1[k];
                    }
                    //cout<<" ";
                    for(int k=i;k<=i+ls[j]-1;k++){
                        y+=l2[k];
                        //cout<<l2[k];
                    }
                    //cout<<"     ";
                    if(mp[x]==y&&x==s1[j]) ans++;
                }
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
