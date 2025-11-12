#include<bits/stdc++.h>
using namespace std;
struct jk{
    int a,b;
};
bool cmp(jk a,jk b)
{
    return a.a>b.a;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    jk c[a*b];
    for(int i=0;i<a*b;i++)
    {
        cin>>c[i].a;
        c[i].b=i;
    }
    sort(c,c+a*b,cmp);
    int sum=0,sum1;
    for(int i=0;i<a*b;i++)
    {
        if(c[i].b==0)
        {
            sum=i;
        }
    }
    if((sum/a+1)%2==1) cout<<sum/a+1<<" "<<sum%a+1;
    else cout<<sum/a+1<<" "<<a-(sum%a);
    return 0;
}
