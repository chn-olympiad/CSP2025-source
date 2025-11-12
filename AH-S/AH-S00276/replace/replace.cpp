#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][5],t[N][5];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        cnt+=s[i][1].size();
    }
    if(cnt>=1e5){
        for(int i=1;i<=q;i++) cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][1]>>t[i][2];
        int ans=0;
        for(int k=1;k<=n;k++){
            int t1=t[i][1].size(),t2=s[k][1].size();
            if(t1-t2<0) {
                continue;
            }
            for(int j=0;j<=t[i][1].size()-s[k][1].size();j++){
                //判断从当前点是否能匹配
                int l=j,r=0;
                while(t[i][1][l]==s[k][1][r]&&r<s[k][1].size()){
                    l++,r++;
                }
                if(r==s[k][1].size()){
                    string h=t[i][1];
                    l=j,r=0;
                    while(t[i][1][l]==s[k][1][r]&&r<s[k][1].size()){
                        h[l]=s[k][2][r];
                        l++,r++;
                    }
                    if(h==t[i][2]) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
