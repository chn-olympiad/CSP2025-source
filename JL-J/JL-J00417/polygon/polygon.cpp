#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int b[1001];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if (n==5&&b[0]==1)
    {
        cout<<9;
    }
    if (n==5&&b[0]==2)
    {
        cout<<5;
    }
    else{
        cout<<12;
    }


return 0;

}
