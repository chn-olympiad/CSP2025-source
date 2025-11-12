#include<bits/stdc++.h>
using namespace std;
int n,q;
struct s{
    string s1,s2;
}s[200005];
string t1,t2;
map<string,string> ma;
int tl[1000005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].s1>>s[i].s2;
        ma[s[i].s1]=s[i].s2;
        tl[s[i].s1.size()]=1;
    }
    for(int qu=1;qu<=q;qu++){
        cin>>t1>>t2;
        int s=0;
        for(int i=1;i<=5000000;i++){
            if(tl[i]==0){
                continue;
            }
            int len=t1.size();
            for(int j=0;j<len;j++){
                if(ma[t1.substr(j,i)]!=""){
                    string x=t1.substr(0,j),y=t1.substr(j,i),z=t1.substr(j+i,n-(j+i)+1);
                    if(t2==x+y+z){
                        s++;
                    }
                }
            }
        }
        cout<<s;
    }
    return 0;
}
