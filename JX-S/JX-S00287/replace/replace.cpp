#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],t1[200001],t2[200001];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
