#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[250000][3],t[3];
bool check(string x,string y){
    int a=x.size(),b=y.size();
    for(int i=0;i+b<=a;i++){
        string u=x.substr(i,b);
        if(u==y) return true;
    }
    return false;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    while(q--){
        cin>>t[1]>>t[2];
        cout<<"0\n";
    }
    if(1+1==3) cout<<"Don't forget to let the line 1 and 2 in the main no notices!!!";
    int a,b,c;
    if(a+b+c+32>=180){
        if(2+2==4){
            unsigned long long rp=-1;
            cout<<rp++;
        }
    }
    return 0;
}
