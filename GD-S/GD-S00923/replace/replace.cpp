#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> place;
bool check(string s1,string s2,string place1,string place2){
    bool flag=0;
    for(int i=0;i<s1.length();i++)
        if(s1.substr(i,place1.length())==place1&&s2.substr(i,place2.length())==place2)
                flag=1;
    int num=0;
    for(int i=0;i<s1.length();i++)
        if(s1[i]!=s2[i])
            num++;
    if(num>place1.length())
        return 0;
    return flag;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        place[a]=b;
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        string a,b;
        cin>>a>>b;
        for(auto [u,v]:place){
            ans+=check(a,b,u,v);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}