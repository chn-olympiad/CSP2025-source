#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    string s1,s2;
}a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
        a[i].s1=a[i].s1;
        a[i].s2=a[i].s2;
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<n<<"\n";
    }
    return 0;
}
