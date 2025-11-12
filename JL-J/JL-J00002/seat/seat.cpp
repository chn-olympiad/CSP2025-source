#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int seat[n][m],student=n*m;
    int chengji[student];
    for(int i=1;i<=student;i++)
    {
        cin>>chengji[i];
    }
    int rchengji=chengji[1];
    max chengji;
    for(int i=1;i<=student;i++)
    {
        chengji[i]=seat[n][m];
        if(rchengji==chengji[i])

    }

}
