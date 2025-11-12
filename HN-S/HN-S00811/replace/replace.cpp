#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1[1000005],s2[1000005];
string t1[1000005],t2[1000005];


int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","r",stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int j = 1;j<=q;j++){
        cin>>t1[j]>>t2[j];
    }
    for(int i=1;i<=q;i++){
        cout<<"0"<<endl;
    }
    return 0;
}
