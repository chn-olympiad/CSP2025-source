#include<bits/stdc++.h>
using namespace std;
const int N=1E6+10;
struct node{
    bool v;
    string s;
};
string s[N];
int tot;
int cnt;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1]={1,s2};
    }
    int ans;
    while(m--){
        string s1,s2;
        cin>>s1>>s2;
        bool flag=1;
        ans=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(flag){
                    s[++tot]=s1[i];
                    flag=0;
                    ans++;
                }
                else s[tot]+=s1[i];
            }
            else flag=1;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
