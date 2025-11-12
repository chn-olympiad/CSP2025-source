#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.in","w",stdin);
    string s;
    int b[10];
    int a,j,ans=0;
    getline(cin.s)
    do{
        s/=10;
        ans++;
    }while(s!=0);
    for(int i=1;i<=ans;i++)
    {
        a=s%10;
        j=a;
        if(a=1||a=2||a=3||a=4||a=5||a=6||a=7||a=8||a=9||a=0)b[j]=a;
        else continue;
        sort(a+1;a+b[j]+1);
        cout<<b[j];
    }
    return 0;
}
