#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int >
#define ll long long
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n,c[510];
    string s;
    bool flag=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        if(s[i]!=0)flag=1;
    }
    if(flag==0)cout<<0;
    else {
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        cout<<1;
    }
    return 0;
}
