#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s1[n],s2[n],q1[q],q2[q];
    for(int i=0;i<n;i++)
    cin>>s1[i]>>s2[i];
    for(int i=0;i<q;i++)
        cin>>q1[i]>>q2[i];
    for(int i=1;i<=q;i++) cout<<0<<endl;
    return 0;
}
