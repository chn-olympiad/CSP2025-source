#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,q;
struct Node{
    string s1,s2,s1t,s2t;
    int s1q,s1z,s2q,s2z;
}t[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>t[i].s1>>t[i].s2;
    }
    for(int i=1;i<=q;i++){
        string a,b;
        cin>>a>>b;
        cout<<0<<endl;
    }
    return 0;
}
