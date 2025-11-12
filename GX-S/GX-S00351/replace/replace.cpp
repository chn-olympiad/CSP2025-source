#include<bits/stdc++.h>
using namespace std;
struct aaa{
    string a,b;
}eyz[200003];
string s="hello";
int n,q;
void f(string s1,string s2){
    int ans=0,t1;
    string t;
    for(int i=0;i<n;i++){
        t=s1;
        t1=t.find(eyz[i].a);
        if(t1<t.size()){
            t.erase(t1,eyz[i].a.size());
            t.insert(t1,eyz[i].b);
            if(t==s2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string s1,s2;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>eyz[i].a>>eyz[i].b;
    }
    for(int i=0;i<q;i++){
        cin>>s1>>s2;
        f(s1,s2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
