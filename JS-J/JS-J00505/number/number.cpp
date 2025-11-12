#include<bits/stdc++.h>
using namespace std;
char c[100001];int y[10];int sum=0;
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<=100001;i++)
    {
        if(c[i]>='0'&&c[i]<='9')
        {
            y[c[i]-'0']++;


        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=y[i];j++)
            cout<<i;

    }
    return 0;
}
