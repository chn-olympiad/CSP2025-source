#include <bits/stdc++.h>
using namespace std;
int a1num,a2num,a3num;
int a1,a2,a3;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t,n;
    cin>>t>>n;
    while(t--){
            int maxn=-100;
        for(int i=1;i<=n;i++){
            cin>>a1>>a2>>a3;
            maxn=max(a2,a1);
            maxn=max(maxn,a3);
        }
        if(maxn==a1) a1num++;
        if(maxn==a2) a2num++;
        else a3num++;
    }
    int h=n/2;
    if(a1num<=h&&a2num<=h&&a3num<=h)
        cout<<a1num+a2num+a3num;
    return 0;
}
