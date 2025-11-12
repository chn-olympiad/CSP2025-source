#include <bits/stdc++.h>
using namespace std;
int sum[1000000];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n=s.length(),a=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            sum[a]=s[i]-48;
            a++;
        }
    }
    sort(sum,sum+a,cmp);
    for(int i=0;i<a;i++)
    {
        printf("%d",sum[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
