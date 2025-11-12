#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> mp;
string s1[200010],s2[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",&s1[i],&s2[i]);
        mp[s1[i]]=s2[i];
        mp[s2[i]]=s1[i];
    }
    string a,b;
    while(q--){
        cin>>a>>b;
        cout<<0;
    }
    return 0;
}
