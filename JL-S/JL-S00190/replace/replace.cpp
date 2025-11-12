#include<bits/stdc++.h>
using namespace std;
string  a,b;
int delt[200005];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int x[2],y=0;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j]){
                x[y]=j;
                y++;
            }
        }
        delt[i]=x[1]-x[0];
    }
    while(q){
        string s,d;
        cin>>s>>d;
        int x[2],y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==d[i]){
                x[y]=i;
                y++;
            }
        }
        int k=x[1]-x[0],ans=0;
        for(int i=0;i<n;i++){
            if(delt[i]==k) ans++;
        }
        cout<<ans<<endl;
        q--;
    }
    return 0;
}

