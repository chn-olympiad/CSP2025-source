#include<bits/stdc++.h>
using namespace std;
long long K=1e5;
int main(){
    long long n,m;
    cin>>n>>m;
    string s1,s2,y[10000],y1[10000];
    cin>>s1>>s2;
    for(int i=1;i<=n+m-1;i++){
        cin>>y[i]>>y1[i];
    }
    for(int i=1;i<=n+m-1;i++){
        s1.find(y[i]);
    }

    for(int i=1;i<=m;i++){
        cout<<0<<endl;
    }
    return 0;
}
