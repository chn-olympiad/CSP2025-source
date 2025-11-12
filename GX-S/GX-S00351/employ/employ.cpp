#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0,n,m,t;
int main(){
    freopen("empoly.in","r",stdin);
    freopen("empoly.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)cin>>t;
    for(int i=1;i<=n-m+1;i++){
        cnt+=i;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
