#include<bits/stdc++.h>
using namespace std;
string s,q="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x=s.size();
    for(int i=0;i<=x-1;i++){
        if(s[i]>=48 and s[i]<=57){
            q+=s[i];
        }
    }
    sort(q.begin(),q.end());
    for(int i=q.size()-1;i>=0;i--){
        cout<<q[i];
    }
}
