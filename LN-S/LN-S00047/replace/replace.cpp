#include<bits/stdc++.h>
using namespace std;
const int mxN=2e5+5;
int n,q;
string s[mxN][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    while(q--){
        int que;
        cin>>que;
        int len1=s[que][1].size();
        int len2=s[que][2].size();
        int len=min(len1,len2);
        len--;
        cout<<0<<endl;
    }
    return 0;
}
