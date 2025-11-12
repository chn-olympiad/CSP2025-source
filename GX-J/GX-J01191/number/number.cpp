#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[1000005];
int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    cin >> s;
    int sum=0;
    for(int i=0;i<=s.size();++i)
    {
        char b=s[i];
        if(b >= '0' && b <='9')
        {
            sum++;
            a[i]=b-48;
        }
    }
    int ans=0;
    while(true)
    {
        ans=0;
        for (int j=2;j<=sum;++j)
        {
            if(a[j]>a[j-1])
            {
                int e=a[j-1];
                a[j-1]=a[j];
                a[j]=e;
                ans++;
            }
        }
        if(ans==0)
            break;
    }
    for(int i=1;i<=sum;++i)
        cout << a[i];
    return 0;
}
