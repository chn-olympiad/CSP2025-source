#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(int i=0;i<t1.size();i++){
            for(int j=1;j<=n;j++){
                int is=1;
                for(int k=i;k<s1[j].size();k++){
                    if(s1[j][k]!=t1[i]) is=0;
                }
                if(is){
                    int b=1;
                    for(int k=0;k<s2[j].size();k++){
                        if(s2[j][k]!=t2[k]) b=0;
                    }
                    for(int k=s2[j].size();k<t1.size();k++){
                        if(t1[k]!=t2[k]) b=0;
                    }
                    if(b==1) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
