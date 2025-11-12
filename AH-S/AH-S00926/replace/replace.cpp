#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,q;
string a,b,p[200005];
map<string,string> m;
int change(string a){
    if(a==b)return 1;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=a.find(p[i]);
        if(x!=-1){string t=a;
            t.erase(x,p[i].size());
            t.insert(x,m[p[i]]);
            //for(int j=0;j<p[i].size();j++)t[i+x]=m[p[i]][j];
            ans+=(t==b);
        }
    }return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>b;
        m[p[i]]=b;
    }while(q--){
        cin>>a>>b;
        cout<<change(a)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
