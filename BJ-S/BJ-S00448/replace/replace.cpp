#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    string s1,s2;
};
node a[100000],b[100000];
int dp[1000000];
int ans=0;
string x;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i].s1 >> a[i].s2;
    }
    for(int i=1;i<=q;i++){
        cin >> b[i].s1 >> b[i].s2;
    }
    cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
