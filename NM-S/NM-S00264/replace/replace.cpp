#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const ull N=5000010,P=13331;
unordered_map<ull,ull> m;
int n,q;
ull ha[N],p[N],h;
ull geth(int l,int r){
    return ha[r]-ha[l-1]*p[r-l+1];
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    p[0]=1;
    for(int i=1;i<=N-1;i++){
        p[i]=p[i-1]*P;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        ull h1=0,h2=0;
        for(int i=0;i<s1.size();i++){
            h1=h1*P+s1[i];
        }
        for(int i=0;i<s2.size();i++){
            h2=h2*P+s2[i];
        }
        m.insert({h1,h2});
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int ans=0;
        memset(ha,0,sizeof(ha));
        h=0;
        for(int i=1;i<=s1.size();i++){
            ha[i]=ha[i-1]*P+s1[i-1];
        }
        for(int i=1;i<=s2.size();i++){
            h=h*P+s2[i-1];
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=i;j<=s1.size();j++){
                if(m.count(geth(i,j))){
                    ull tmp=m[geth(i,j)];
                    if(ha[s1.size()]-geth(i,j)*p[s1.size()-j]+tmp*p[s1.size()-j]==h){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
