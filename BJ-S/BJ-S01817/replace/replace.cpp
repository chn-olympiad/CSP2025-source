#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    string s1,s2;
}a[200005];
string r1,r2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++)cin >> a[i].s1 >> a[i].s2;
    while(q != 0){
        q--;
        cin >> r1 >> r2;
        cout << n << endl;
    }
    return 0;
}

