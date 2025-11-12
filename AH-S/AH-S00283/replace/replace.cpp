#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,fr[200005],cha[200005];
string re[200005][2],qu[200005][2];
int check(){
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=1;j++){
            int l;
            l = re[i][j].size();
            int cnt;
            cnt = 0;
            for(int k = 0;k<l;k++){
                if(re[i][j][k] == 'b'){
                    if(++cnt>1){
                        return 0;
                    }
                }else if(re[i][j][k]!='a'){
                    return 0;
                }
            }
        }
    }
    for(int i = 1;i<=q;i++){
        for(int j = 0;j<=1;j++){
            int l;
            l = qu[i][j].size();
            int cnt;
            cnt = 0;
            for(int k = 0;k<l;k++){
                if(qu[i][j][k] == 'b'){
                    if(++cnt>1){
                        return 0;
                    }
                }else if(qu[i][j][k]!='a'){
                    return 0;
                }
            }
        }
    }
    return 1;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>re[i][0]>>re[i][1];
    }
    for(int i = 1;i<=q;i++){
        cin>>qu[i][0]>>qu[i][1];
    }
    if(check()){
        for(int i = 1;i<=n;i++){
            int l;
            l = re[i][0].size();
            for(int j = 0;j<l;j++){
                if(re[i][0][j] == 'b'){
                    fr[i] = j;
                    cha[i] = j;
                    break;
                }
            }
            for(int j = 0;j<l;j++){
                if(re[i][1][j] == 'b'){
                    cha[i] = j-cha[i];
                    break;
                }
            }
        }
        for(int i = 1;i<=q;i++){
            int l,c,f,ans;
            ans = 0;
            l = qu[i][0].size();
            for(int j = 0;j<l;j++){
                if(qu[i][0][j] == 'b'){
                    c = j;
                    f = j;
                    break;
                }
            }
            for(int j = 0;j<l;j++){
                if(qu[i][1][j] == 'b'){
                    c = j-c;
                    break;
                }
            }
            for(int j = 1;j<=n;j++){
                if(cha[j] == c && fr[j]<=f && f-fr[j]+re[j][0].size()<=l){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }else{
        for(int i = 1;i<=q;i++){
            int l,ans;
            ans = 0;
            l = qu[i][0].size();
            for(int j = 1;j<=n;j++){
                int L;
                L = re[j][0].size();
                for(int k = 0;k+L<=l;k++){
                    int f;
                    f = 1;
                    for(int h = 0;h<L;h++){
                        if(qu[i][0][k+h]!=re[j][0][h] || qu[i][1][k+h]!=re[j][1][h]){
                            f = 0;
                            break;
                        }
                    }
                    for(int h = k+L;h<l;h++){
                        if(!f){
                            break;
                        }
                        if(qu[i][0][h]!=qu[i][1][h]){
                            f = 0;
                            break;
                        }
                    }
                    if(f){
                        ans++;
                        break;
                    }
                    if(qu[i][0][k]!=qu[i][1][k]){
                        break;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
