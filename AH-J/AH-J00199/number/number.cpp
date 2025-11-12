#include <bits/stdc++.h>
using namespace std;

const int N=1e6+6;
int a[N],p,n;
string s;

int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    n=s.size();
    for (char c:s) {
        if (isdigit(c)) a[++p]=c-'0';
    }
    sort(a+1,a+p+1,[](int x,int y){
         return x>y;
    });
    for (int i=1;i<=p;i++) cout<<a[i];
    return 0;
}
