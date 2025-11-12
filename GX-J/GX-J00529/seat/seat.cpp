#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b)
{
    if(a>=b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];

    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            x=i;
        }
    }
    int hang=0,lie=0;
    if(x%n==0)
    {
        hang=n;
        lie=x/n;
    }
    else
    {
        hang=x%n;
        lie=(x/n)+1;
    }
    cout<<lie<<" "<<hang<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
