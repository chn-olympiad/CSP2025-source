#include<bits/stdc++.h>
using namespace std;
string s;
int ans,a[1000050];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen(number.in,"r",stdin);
    freopen(number.out,"w",stdout);
    ios::sync_with_stdio(false);
    cin>>s;
    int m=0;
    for(int i=0;i<sizeof(s);i++)
    {
        int num=s[i]-'0';
        if(num==1||num==2||num==3||num==4||num==5||num==6||num==7||num==8||num==9||num==0)
        {
            a[++m]=num;
        }
    }
    sort(a+1,a+m,cmp);
    for(int i=1;i<=m;i++)
    {
        cout<<a[i];
    }
    return 0;
}
