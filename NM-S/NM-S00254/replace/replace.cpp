#include<bits/stdc++.h>
using namespace std;
int n,q,xx[200050][3],zz[200050][3],cc[200050],ans;
string s1,s2,ss[200050][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>ss[i][1]>>ss[i][2];
        s1 = ss[i][1];
        int x1,x2,z1,z2,c,p1,p2;
        for(int i = 0;i<s1.length();i++){
            if(s1[i] == 'b'){
                p1 = i;
                break;
            }
        }
        xx[i][1] = p1;
        zz[i][1] = s1.size()-p1-1;
        s2 = ss[i][2];
        for(int i = 0;i<s2.length();i++){
            if(s2[i] == 'b'){
                p2 = i;
                break;
            }
        }
        xx[i][2] = p2;
        zz[i][2] = s2.size()-p2-1;
        cc[i] = p1-p2;
    }
    while(q--){
            ans = 0;
        cin>>s1>>s2;
        int x1,x2,z1,z2,c,p1,p2;
        for(int i = 0;i<s1.length();i++){
            if(s1[i] == 'b'){
                p1 = i;
                break;
            }
        }
        x1 = p1;
        z1 = s1.size()-p1-1;
        for(int i = 0;i<s2.length();i++){
            if(s2[i] == 'b'){
                p2 = i;
                break;
            }
        }
        x2 = p2;
        z2 = s2.size()-p2-1;
        c = p1-p2;
        for(int i = 1;i<=n;i++){
            if(xx[i][1]<=x1&&xx[i][2]<=x2&&zz[i][1]<=z1&&zz[i][2]<=z2&&c == cc[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
