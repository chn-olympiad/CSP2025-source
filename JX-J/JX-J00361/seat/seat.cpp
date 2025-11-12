#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
struct student
{
    int id;
    int score;
}a[N];
bool cmp(student x,student y)
{
    return x.score>y.score;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)
        {
            if(i%n==0)
            {
                if((i/n)%2==0)
                {
                    cout<<i/n<<" "<<1<<endl;
                }
                else
                {
                    cout<<i/n<<" "<<n<<endl;
                }
            }
            else
            {
                if((i/n)%n==1)
                {
                    cout<<i/n+1<<" "<<n-i%n+1<<endl;
                }
                else
                {
                    cout<<i/n+1<<" "<<i%n<<endl;
                }
            }
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
