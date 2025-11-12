#include<bits/stdc++.h>
using namespace std;
string s[10005],o,t[10005],p;
int n,q,ans=0,flag=0;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    cin>>p>>o;
    for(int i=1;i<=n;i++){
        for(int y=1;y<=p.length();y++){
            if(p[y]==s[i][1]){
                for(int d=1;d<=s[i].length();d++){
                    if(p[y+d]!=s[i][d+1]){
                        flag=1;
                        continue;
                    }
                }
                if(flag==0){
                    for(int d=0;d<=t[i].length()-1;d++){
                        if(o[y+d]!=t[i][d]){
                            flag=1;
                        }
                    }
                    for(int d=0;d<=y;d++){
                        if(o[d]!=p[d]){
                            flag=1;
                        }
                    }
                    for(int d=y+t[i].length();d<=p.length();d++){
                        if(o[d]!=p[d]){
                            flag=1;
                        }
                    }
                    if(flag==0){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
