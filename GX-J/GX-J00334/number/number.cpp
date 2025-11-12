#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    string n;
    long long a[1000005],num=0;
    getline(cin,n);
    for(int i=0;i<n.size();i++)
    {
        if(n[i]>=0&&n[i]<=9)
        {
            num++;
            a[num]=(int)n[i];
        }
    }
    for(int j=num;j>1;j--)
    {
        for(int k=1;k<=j;k++)
        {
            if(a[k]<a[k+1])
                swap(a[k],a[k+1]);
        }
    }
    for(int m=1;m<=num;m++)
    {
        cout<<a[m];
    }
    return 0;
}
