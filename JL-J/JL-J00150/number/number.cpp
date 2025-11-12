#include <bits/stdc++.h>

using namespace std;
long long cnt;
char a[1000000+10],b[1000000+10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=1000000;i++){
        if(a[i]<='9'&&a[i]>='0'){
            b[cnt]=a[i];
            cnt++;
        }
    }
    sort(b,b+cnt);
    for(int i=cnt;i>=1;i--){
        cout<<b[i];
    }
    return 0;
}
