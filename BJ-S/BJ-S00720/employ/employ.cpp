#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],pds=0;
int paipai(int x,int y){
    int a=1,b=1;
    for(int i=1;i<=x;i++)a*=i;
    for(int i=1;i<=y;i++)b*=i;
    return a/b;
}
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=0;i<s.size();i++){//pds ok
        if(s[i]=='1')pds++;
    }
    if(n==m){
        if(pds==n){
            cout<<"1";return 0;
        }
        else cout<<"0";return 0;
    }
    if(pds==n){
        cout<<paipai(n,m);return 0;
    }
    return 0;
}
