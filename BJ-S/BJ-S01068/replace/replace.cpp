#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q;
string s1[N];
string s2[N];
string t1,t2;
int a1[N],a2[N];
long long ans=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i];
        cin>>s2[i];
        a1[i]=s1[i].find("b");
        a2[i]=s2[i].find("b");
    }
    for(int i=1;i<=q;i++){
            ans=0;
            cin>>t1>>t2;
            if(t1.size()!=t2.size()) cout<<0<<endl;
            int b1=-1,b2=-1;
            b1=t1.find("b");
            b2=t2.find("b");
            for(int j=1;j<=n;j++){
                if(b1>=a1[j]&&((a1[j]-a2[j])==(b1-b2))) ans++;
            }
            cout<<ans<<endl;
    }
    return 0;
}