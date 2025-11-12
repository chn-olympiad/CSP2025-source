#include<bits/stdc++.h>
using namespace std;
int n,m,score=1;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
        {
            score++;
        }
    }
    int ai=score/n,aj;
    if(score%n!=0)
    {ai++;}
    if(ai%2==0)
    {
        aj=n-score+(ai-1)*n+1;
    }else{
        aj=score-(ai-1)*n;
    }
    cout<<ai<<" "<<aj;
    return 0;
}
