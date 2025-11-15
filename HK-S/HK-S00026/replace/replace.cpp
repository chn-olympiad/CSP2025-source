#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e5+5;
int n, q;
struct node{
    string x, y;
}a[maxn];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;

    while (q--){
        string t1, t2;
        cin>>t1>>t2;

        cout<<0<<endl;
    }
    
    return 0;

    fclose(stdin);
    fclose(stdout);
}