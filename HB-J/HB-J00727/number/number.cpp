#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a;i <= b;i++)
#define dep(i,a,b) for(int i = a;i >= b;i--)
using namespace std;
string n;
int len;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> n;
    len = n.length();
    int j = 0;
    rep(i,0,len-1){
        //cout << n[i] - '0' << ' ';
        if(n[i] - '0' >= 0 && n[i] - '0' <= 9){
            a[++j] = n[i]-'0';
        }
    }
    sort(a+1,a+1+j);
    dep(i,j,1){
        cout << a[i];
    }
    return 0;
}
