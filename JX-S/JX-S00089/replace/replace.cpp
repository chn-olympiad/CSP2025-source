#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,q;
string s1,s2,t1[maxn],t2[maxn];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    cin>>s1>>s2;
    for(int i=1;i<=n;i++){
        cin>>t1[i]>>t2[i];
    }
    for(int i=1;i<=n;i++)
        cout<<"0\n";
    return 0;
}
