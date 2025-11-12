#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[200010],s2[200010];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<'\n';
            continue;
        }
        int ans=0,lst=-1,pre=-1;
        for(int j=0;j<t1.length();j++){
            if(t1[j]!=t2[j]){
                if(pre==-1){
                    pre=j;
                }
                lst=j;
            }
        }
        for(int j=1;j<=n;j++){
            int tmp=t1.find(s1[j]),tmp2=t2.find(s2[j]);
            //cout<<tmp<<" "<<tmp2<<'\n';
            if(tmp>=0&&tmp<t1.length()&&tmp2>=0&&tmp2<t2.length()&&tmp<=pre&&tmp+s1[j].length()-1>=lst){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
