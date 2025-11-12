#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu
{
    int v;
    int i;
}a[105];
bool cmp(stu x,stu y)
{
    return x.v>y.v;
}
string count(int i)
{
    string res="";
    int x=ceil(1.0*i/n);
    int y=i%n;
    if(y==0)
    {
        y=n;
    }
    res=to_string(x)+" ";
    if(x%2==0)
    {
        res+=to_string(n-y+1);
    }
    else
    {
        res+=to_string(y);
    }
    return res;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i].v;
        a[i].i=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        //cout << a[i].v << " ";
        if(a[i].i==1)
        {
            cout << count(i);
        }
    }
    return 0;
}
