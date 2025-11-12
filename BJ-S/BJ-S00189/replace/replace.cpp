#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
string s1[N],s2[N],t1,t2,r1;
int n,q;
signed main(){

    // march 7th world best!
    //freopen()
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        cin>>t1>>t2;
        int m=t1.size();
        int jd=0,lst=0,ans=0,flag=1;
        for(int i=1;i<=n;i++){
            int flag=1;
            for(int j=0;j<m;j++){
                if(s1[i][jd]==t1[jd+lst])jd++;
                else {
                    for(int k=lst;k<=j;k++)if(t1[k]!=t2[k])flag=0;
                    lst=j+1,jd=0;
                }
                if(jd==s1[i].size() && flag){
                    
                    string t;
                    for(int k=0;k<lst;k++){
                        t+=t1[k];
                    }t+=s2[i];
                    for(int k=j+1;k<m;k++)t+=t1[k];
                    lst=j+1;jd=0;
                    // cerr<<s1[i]<<" "<<t<<endl;
                    if(t==t2)ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}