#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+89;

string s[maxn][3];
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    while(q--){
        string t,tt;
        cin>>t>>tt;
        int ans=0;
        for(int i=1;i<=n;i++){
            string s1=s[i][1],s2=s[i][2];
            int last=0;
            while(1){
                int pos=t.find(s1,last);
                if(pos!=-1){
                    string temp=t,ss=t.replace(pos,s1.size(),s2);
                    t=temp;
                    last=pos+1;
                    if(ss==tt)ans++;
                }else break;
                if(last>t.size()-1)break;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}



