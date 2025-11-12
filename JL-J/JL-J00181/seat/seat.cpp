#include<bits/stdc++.h>;
using namespace std;
int n,m;
int a[20][20];
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int score[110];
    cin>>n>>m;
    int shu=n*m;
    for(int i=1;i<=shu;i++)
            cin>>score[i];
    for(int i=1;i<=shu;i++)
    {
        if(max(score[i],score[i-1])=score[i])
        {
            swap(score[i],score[i-1]);
            score[i]=a[n][m];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=score[i];
            score[1]=a[max(i,n)][max(j,m)];
        }
    }
    cout<<score[1];


    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
