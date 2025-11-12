#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("numbur.in","r",stdin);
    freopen("numbur.out","w",stdout);
    char a[100001],b[1001];
    int j=0;
    for(int i=0;i<100001;i++) cin>>a[i];
    for(int i=0;i<100001;i++)
    {
        if('a[i]'>='0'&&'a[i]'<='9')
        {
            b[j]=a[i];
            j++;
        }
    }
    char c[j-1];
    sort(c,c+j-1);
    for(int i=j-1;i>=0;i--) cout<<c[i];
    return 0;
}
