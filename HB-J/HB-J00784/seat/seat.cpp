#include<bits/stdc++.h>
using namespace std;
bool cmp(int tg1,int tg2)
{
    if (tg1>tg2)
        return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,qu[1001];
    cin>>n>>m;
    for (int i=0;i<n*m;i++)
    {
        cin>>qu[i];
    }
    int ltr=qu[0],ltrpos;
    sort(qu,qu+n*m,cmp);
    for (ltrpos=0;ltrpos<n*m;ltrpos++)
        if (qu[ltrpos]==ltr)
        break;
    int anscol=ltrpos/n+1,ansrow;
    if (anscol%2==1)
        ansrow=ltrpos-(anscol-1)*n+1;
    else
        ansrow=n-(ltrpos-(anscol-1)*n+1)+1;
    cout<<anscol<<" "<<ansrow;
    return 0;
}
