#include<bits/stdc++.h>
using namespace std;
long long i,b[200001]={0},y,k,number=0;
string a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    if(a.size()>200001)
    {
        cout<<a;
        return 0;
    }
    for(i=0;i<a.size();i++)
    {
            if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
            {
                b[number]=a[i]-48;
                number++;
            }

    }
   for(i=0;i<number;i++)
    {
        for(y=i+1;y<number;y++)
        {
            if(b[i]<b[y])
            {
                k=b[i];
                b[i]=b[y];
                b[y]=k;
            }
        }
    }
    for(i=0;i<number;i++)
    {
        cout<<b[i];
    }
    return 0;
}
