#include <bits/stdc++.h>

using namespace std;

#define N 1000005

char a[N],b[N];

bool cmp(char x,char y)
{
    if((x-'0')>(y-'0'))
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    int j,k=0;
    for(j=0;j<i;j++)
    {
        if(isdigit(a[j]))
        {
            b[k]=a[j];
            k++;
        }
    }
    sort(b,b+k,cmp);
    for(j=0;j<=k;j++)
    {
        cout<<b[j];
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
