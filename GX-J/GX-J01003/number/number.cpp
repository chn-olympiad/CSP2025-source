#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int j=0;
    for(int i=0;i<a.size();i++)
    {
        int sum=a[i]-'0';
        if(sum==9||sum==8||sum==7||sum==6||sum==5||sum==4||sum==3||sum==2||sum==1||sum==0)
        {

            b[j]=sum;
            j++;

        }

    }
    sort(b,b+j,cmp);
    for(int i=0;i<j;i++)
    {
        cout <<b[i];
    }
    return 0;
}
