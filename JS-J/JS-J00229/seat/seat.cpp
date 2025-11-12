#include<bits/stdc++.h>
using namespace std;
int n,m,N,cnt=1;
int tn,tm,ansn,ansmt,ansm;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    N=n*m;
    for(int i=1;i<=N;i++) cin>>a[i];
    for(int i=2;i<=N;i++)
    {
        if(a[1]<a[i]) cnt++;
    }
    ansmt=cnt/(n*2);
    if(cnt%(n*2)!=0) ansmt++;
    cnt-=(ansmt-1)*n*2;
    //cout<<ansmt<<" "<<cnt<<"\n";
    if(cnt>n)
    {
        ansn=2*n-cnt+1;
        ansm=ansmt*2;
    }
    else
    {
        ansn=cnt;
        ansm=ansmt*2-1;
    }
    //cout<<n<<" "<<m<<"\n";
    cout<<ansm<<" "<<ansn;
    return 0;

}
