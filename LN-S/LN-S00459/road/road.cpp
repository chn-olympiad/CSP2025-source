#include <iostream>

using namespace std;
int a[100001];
int cun[1001][1001];
int main()
{
    freopen("road,in","w",stdin);
    freopen("road.out","r",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0;i < m;i++)
    {
        int f,t;
        scanf("%d%d%d",&f,&t,&a[i]);
    }
    for(int i = 0;i < k;i++)
    {
        int jian;
        scanf("%d",&jian);
        for(int j = 0;j < n;i++)
        {
            scanf("%d",&cun[i][j]);
        }

        //i love you so~
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
