#include<bits/stdc++.h>
using namespace std;
long long n,m,ansn,ansm,score[10005],sR,num;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n*m;i++)
    {
        cin>>score[i];
    }
    sR=score[0];
    sort(score,score+n*m,cmp);
    for(long long i=0;i<n*m;i++)
    {
        if(sR==score[i])
        {
            num=i+1;
            break;
        }
    }
    ansm=num/n;
    if(ansm*n!=num)
        ansm+=1;
    ansn=num%n;
    if(ansn==0)
        ansn=n;
    if(ansm%2==0)
        ansn=n-ansn+1;
    cout<<ansm<<' '<<ansn;
    return 0;
}
