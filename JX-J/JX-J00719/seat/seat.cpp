#include <bits/stdc++.h>
using namespace std;
int n,m,once;
vector<int> a;
bool cmp(int s1,int s2)
{
    if(s1>s2) return true;
    else return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++)
    {
        scanf("%d",&once);
        a.push_back(once);
    }
    int x=a[0];
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==x)
        {
            int get1=i/n+1,get2=i%n;
            if(get1%2==1) printf("%d %d",get1,get2+1);
            else printf("%d %d",get1,n-get2);
            return 0;
        }
    }
    return 0;
}
