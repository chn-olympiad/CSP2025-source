#include <bits/stdc++.h>
using namespace std;
int a[11],b[1];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=10;i++){
        cin>>a[i];
    }
    a[1]=b[1];
    sort(a+1,a+1+10);
    for(int j=1;j<=10;j+=){
        if(b[1]==a[j]){
            cout<<n<<" "<<j;
            return 0;
        }
    }
    return 0;
}
