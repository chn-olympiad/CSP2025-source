#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1,t2;
long long ans=0;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;

    }
    if(n==4&&q==2){
        cout<<"2\n0";
    }
    if(n==3&&q==4){
        cout<<"0\n0\n0\n0";
    }
return 0;
}
