#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,flag,ans,a[100000];
string s[10000][3],s1,s2;
char now;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        a[i]=s[i][1].size();
    }
    while(q--){
        cin>>s1>>s2;
        ans=0;
        for(int i=0;i<s1.size();i++){
            for(int q=1;q<=n;q++){
                flag=0;
                for(int v=i;v<=i+a[q]-1;v++){
                    if(s1[v]!=s[q][1][v-i]){flag=1;break;}
                }
                if(flag==0){
                    for(int v=0;v<s1.size();v++){
                        if(v>=i&&v<=i+a[q]-1){now=s[q][2][v-i];}
                        else now=s1[v];
                        if(now!=s2[v]){flag=1;break;}
                    }
                    if(flag==0)ans++;
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}

