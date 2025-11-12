#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int scr[105];
    int R;
    cin>>R;
    scr[0]=R;
    for(int i=1;i<n*m;i++)
        cin>>scr[i];
    int cnt=0;
    sort(scr,scr+n*m,cmp);
    int i;
    for(i=0;i<n*m;i++)
    {
        if(R==scr[i])
            break;
    }
    cnt=i+1;
    int tmp1=cnt/n+1;
    int tmp2=cnt%n;
    if(tmp1%2==1)// 1 3 ....
    {
        if(tmp2!=0)
            cout<<tmp1<<" "<<tmp2;
        if(tmp2==0)
            cout<<tmp1-1<<" "<<n;
    }
    if(tmp1%2==0)//2 4....
    {
        if(tmp2!=0)
            cout<<tmp1<<" "<<n-tmp2+1;
        if(tmp2==0)
            cout<<tmp1-1<<" "<<n;
    }
    cout<<"\n";
    return 0;
}
