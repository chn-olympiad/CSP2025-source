#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010],s1[200010];
string t[200010],t1[200010];
int sx[200010],sx1[200010],sxm[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int f1,f2;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s1[i];
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='b'){
                //cout<<j<<endl;
                sx[i]=j;
            }
        }

        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]=='b'){
                //cout<<j<<endl;
                sx1[i]=j;
            }
        }

        sxm[i]=sx[i]-sx1[i];
    }

    for(int i=1;i<=q;i++){
        cin>>t[i]>>t[i];
    }
    for(int i=1;i<=q;i++){
        int f1,f2,fm;
        for(int j=0;j<t[i].size();j++){
            if(t[i][j]=='b'){
                f1=j;
            }
        }
        for(int j=0;j<t1[i].size();j++){
            if(t1[i][j]=='b'){
                f2=j;
            }
        }
        fm=f1-f2;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(sxm[i]==fm){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
