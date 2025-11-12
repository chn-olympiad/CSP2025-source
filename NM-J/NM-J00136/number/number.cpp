#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
int shuju[MAXN]={0};
int l=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    char temp;
    while(cin>>temp)
    {
        if(temp>='0'&&temp<='9')
        {
            //yes number
            shuju[l]=temp-'0';
            l++;
        }
    }
    sort(shuju,shuju+l);
    for(int i=l-1;i>=0;i--)
    {
        cout<<shuju[i];
    }
    cout<<endl;
    return 0;
}
