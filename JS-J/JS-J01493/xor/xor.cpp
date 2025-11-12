#include<bits/stdc++.h>
using namespace std;
int doit(int x,int y)
{
    return (x^y);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,goal,sum=0;
    cin >> n >> goal;
    int number[n+1]={};
    for(int i=1;i<=n;i++) cin >> number[i];
    bool p=0;
    int tiao=0,now;
    for(int i=n;i>=1;i-=tiao)
    {
        p=0;
        tiao=1;
        now=number[i];
        if(number[i]==goal)
        {
            p=1;
            sum++;
        }
        for(int j=2;j<=i;j++)
        {
            if(p==1) break;
            now=doit(now,number[i-tiao]);
            if(now==goal)
            {
                p=1;
                sum++;
                tiao++;
                break;
            }
            tiao++;
        }
        if(p==0) tiao=1;
    }
    cout << sum;
    return 0;
}
