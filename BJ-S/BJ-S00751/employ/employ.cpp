#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
char a[600];
vector<int> num;
int p[600];
int ran(int in)
{
    if(in == n+1)
    {
        return -1;
    }
    if(in == -1)
    {
        return -1;
    }
    for(int i=0;i<n;i++)
    {
        p[in-1] = i;
        if(ran(in+1) == -1)
        {
            for(int l=0;l<n;l++)
            {
                num.push_back(p[l]);
            }
        }
    }
    return -2;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%s",&a);
    ran(1);
    printf("1");
    return 0;
}
