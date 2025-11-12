#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,q;
map<string ,string> m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string s1,s2;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        m[s1]=s2;
    }
    while(q--){
        cin>>s1>>s2;
        int ans=0;
        s1=" "+s1+" ";
        for(int i=1;i<s1.size()-1;i++){
            for(int j=i;j<s1.size()-1;j++){
                string a=s1.substr(1,i-1);
                string b=s1.substr(i,j-i+1);
                string c=s1.substr(j+1,s1.size()-j-2);
                string s=a+m[b]+c;
                if(s==s2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
