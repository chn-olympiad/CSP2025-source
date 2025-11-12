#include<bits/stdc++.h>
using namespace std;
int b[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("numder.out","w",stdout);
    char a;
    while(cin >> a)
    {
        if(a-'0'==0)
            b[1]++;
        if(a-'0'==1)
            b[2]++;
        if(a-'0'==2)
            b[3]++;
        if(a-'0'==3)
            b[4]++;
        if(a-'0'==4)
            b[5]++;
        if(a-'0'==5)
            b[6]++;
        if(a-'0'==6)
            b[7]++;
        if(a-'0'==7)
            b[8]++;
        if(a-'0'==8)
            b[9]++;
        if(a-'0'==9)
            b[10]++;

    }
    for(int i = 10;i >= 1;i--)
    {
        for(int j = b[i];j>=1;j--)
        {
            cout << i-1;
        }
    }
    return 0;
}
