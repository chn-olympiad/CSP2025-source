#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int n,q;
bool f(string a,string b,int k){
    if(a.find(s1[k])<0||a.find(s1[k])>=a.length())return 0;
    if(b.find(s2[k])<0||b.find(s2[k])>=b.length())return 0;
    string c1="",c2="";
    for(int i=0;i<a.length();i++){
        if(i<a.find(s1[k])||i>=a.find(s1[k])+s1[k].length())c1=c1+a[i];
    }
    for(int i=0;i<b.length();i++){
        if(i<b.find(s2[k])||i>=b.find(s2[k])+s2[k].length())c2=c2+b[i];
    }
    if(c1!=c2)return 0;
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string a,b;
        int ans=0;
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            if(f(a,b,i)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

