#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s;
    long long cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]-'0'==0) cnt++;
    }
    cout<<cnt;
    return 0;
}
