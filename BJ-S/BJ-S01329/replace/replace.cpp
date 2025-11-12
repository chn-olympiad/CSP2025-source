#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2,s,x,y,z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    s=x+y+z;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        if(i&&y=s1){
            y=s2;
            s=x+y+z;
        }
    }
    for(int j=1;j<=q;j++){
        cin>>t1>>t2;
    }
    return 0;
}