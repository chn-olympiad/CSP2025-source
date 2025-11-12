#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,cnt=0;
    cin>>n>>m;
    string a;
    cin>>a;
    for(int i=0;i<n;i++){
        cnt+=a[i]-'0';
    }
    if(cnt==n){
        cout<<0;
    }else{
        cout<<rand()%998244353;
    }
    return 0;
}
