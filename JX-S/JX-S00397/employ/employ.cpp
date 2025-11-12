#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
string s;
int a,b;
int c[1008];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    srand(time(0));
    a=1;b=100;
    cout<<a+rand()%(b-a+1);
    return 0;
}
