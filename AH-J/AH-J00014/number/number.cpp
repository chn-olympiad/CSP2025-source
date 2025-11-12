#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=1;
    char s;
    while(cin>>s)
    {
        if(s>='0'&&s<='9')
        {
            a[cnt]=s-48;
            cnt++;
        }
    }
    sort(a+1,a+cnt);
    if(a[cnt-1]==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=cnt-1;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
