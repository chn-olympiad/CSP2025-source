#include<bits/stdc++.h>
using namespace std;
int n,cd[5010],mxa=0,zc=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cd[i];
        zc+=cd[i];
        mxa=max(mxa,cd[i]);
    }
    if(zc>2*mxa){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}
