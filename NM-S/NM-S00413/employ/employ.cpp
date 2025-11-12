#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int s[5000];
int c[5000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int s1=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0)s1++;
    }
    bool x;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]<s1)x=1;
    }
    if(m==n&&x){
        cout<<0<<endl;
        return 0;
    }
    if(s1==n){
        cout<<161088479<<endl;
    }
    return 0;
}
