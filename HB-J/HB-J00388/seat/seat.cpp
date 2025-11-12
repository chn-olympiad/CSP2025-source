#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a1;
    int h[100]={0};//chengji
    for(int a=0;a<m*n;a++)
    {
        cin>>h[a];
        if(a==0)
        {
            a1=h[a];
        }
    }
    sort(h,h+100);
    int sum=0;
    for(int a=h[99];a>a1;a--)
    {
        sum++;
    }
    int counnt=1;
    if((sum/n+1)%2==0)
    {
            counnt=n;
        for(int a=a1;a<h[99-n*(sum/n)];a++)
        {
            counnt--;
        }
    }
    else{
        for(int a=a1;a<h[99-n*(sum/n)];a++)
        {
            counnt++;
        }
    }
        cout<<sum/n+1<<" ";
     cout<<counnt;
        return 0;
}
