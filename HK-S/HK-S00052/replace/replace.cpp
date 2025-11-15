#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
string s1[maxn],s2[maxn];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        string t1,t2;cin>>t1>>t2;
        int pos1=0,pos2=0;
        string x,y;
        for(int i=0;i<t1.length();i++){
            if(t1[i]=='b'){
                pos1=i;
                x=t1.substr(0,pos1);
                y=t1.substr(pos1+1);
                break;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            string tmp_x,tmp_y;
            for(int j=0;j<s1[i].length();j++){
                if(s1[i][j]=='b'){
                    tmp_x=x.substr(0,x.length()-j);
                    tmp_y=y.substr(s1[i].length()-j-1);
                    break;
                }
            }
            if(tmp_x+s2[i]+tmp_y==t2){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    cout.flush();
    fclose(stdin);fclose(stdout);
    return 0;
}
