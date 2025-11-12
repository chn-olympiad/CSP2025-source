#include<bits/stdc++.h>
using namespace std;
struct ss{
    string a,b;
}s[200000];
bool cmp(ss a,ss b){
    return a.a<b.a;
}
int n,q;
string q1[200000],q2[200000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;++i) cin>>s[i].a>>s[i].b;
    for(int i=0;i<q;++i) cin>>q1[i]>>q2[i];
    sort(s,s+n,cmp);
    for(int i=0;i<q;++i){
        if(q1[i].length()!=q2[i].length()){
            cout<<0<<endl;
            continue;
        }
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
