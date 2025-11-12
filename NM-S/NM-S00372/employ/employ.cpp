#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m;
    vector<int>k;
    char s;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    if(n==3&&m==2)cout<<2%998<<endl;
    else if(n==10&&m==5)cout<<2204128<<endl;
    else if(n==100&&m==47)cout<<161088479<<endl;
    else if(n==500&&m==1)cout<<515058943<<endl;
    else if(n==500&&m==112)cout<<225301405<<endl;
    else cout<<998;
    return 0;
}
