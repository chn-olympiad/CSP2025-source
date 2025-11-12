#include<bits/stdc++.h>
using namespace std;
int score[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,g,littler,tgt,col;
    cin>>n>>m;
    g=n*2;
    for(int j=1;j<=n*m;j++)
    {
        cin>>score[j];
    }
    littler=score[1];
    sort(score+1,score+n*m+1,cmp);
    for(int j=1;j<=n*m;j++)
    {
        if(score[j]==littler)
        {
            tgt=j;
            break;
        }
    }
    col=floor(tgt/g)*2;
    tgt%=g;
    if(tgt==0)
    {
        cout<<col<<" "<<1;
        return 0;
    }
    else if(tgt<=n) cout<<col+1<<" "<<tgt;
    else cout<<col+2<<" "<<g-tgt+1;
    return 0;
}
