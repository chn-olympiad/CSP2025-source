
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>k;
    int tu[n+k][n+k];
    int xiang[k];
    int zongshu=0;
    for(int q=0;q<n;q++)
    {
        int x,y;
        cin>>x>>y;
        cin>>tu[x][y];
        zongshu+=tu[x][y];
    }
    for(int q=0;q<k;q++)
    {
        cin>>xiang[q];
        zongshu+=xiang[q];
        for(int w=0;w<n;w++)
        {
            cin>>tu[q+n][w];
            zongshu+=tu[q+n][w];
        }
    }
    cout<<zongshu;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
