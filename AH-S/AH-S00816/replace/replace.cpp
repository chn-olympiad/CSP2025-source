#include<bits/stdc++.h>
using namespace std;
string str,tar,s[200005][2];
int pos[200005],cnt[200005],n,q,ans,sum;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        for(int j=0;j<s[i][0].size();j++){
            if(s[i][0][j]!=s[i][1][j]){
                pos[i]=j;
                break;
            }
        }
        for(int j=0;j<s[i][0].size();j++){
            if(s[i][0][j]!=s[i][1][j]){
                cnt[i]++;
            }
        }
        sum+=s[i][0].size();
    }
    if((long long)q*(long long)sum>100000000){
        while(q--){
            cin>>str>>tar;
            cout<<0<<'\n';
        }
        return 0;
    }
    while(q--){
        ans=0;
        cin>>str>>tar;
        if(str.size()!=tar.size()){
            cout<<0<<'\n';
            continue;
        }
        int p=0,ct=0;
        for(int i=0;i<str.size();i++){
            if(str[i]!=tar[i]){
                p=i;
                break;
            }
        }
        for(int i=0;i<str.size();i++){
            if(str[i]!=tar[i]){
                ct++;
            }
        }
        for(int j=1;j<=n;j++){
            if(cnt[j]!=ct){
                continue;
            }
            int flag=1;
            for(int k=0,k1=p-pos[j];k<s[j][0].size();k++,k1++){
                if(s[j][0][k]!=str[k1]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                string tmp=str;
                int k,k1;
                for(k=pos[j],k1=p;k<s[j][0].size();k++,k1++){
                    if(tar[k1]!=s[j][1][k]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
