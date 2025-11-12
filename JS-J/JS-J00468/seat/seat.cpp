#include<bits/stdc++.h>
using namespace std;
int a[120];
int t;
int c,r;
int mp[120][120];
bool vis[120][120]= {false};
bool ok[120][120]= {false};
bool cmp(int x,int y)
{
    return x>y;
}
void put(int i,int j,int k)
{
    if(t==mp[i][j])
    {
        cout<<i<<" "<<j;
        return;
    }
    ok[1][1]=true;
    if(i%2==1&&j<r&&ok[i][j+1]==false)
    {
        mp[i][j]=a[++k];
        ok[i][j]=true;
        j++;
        put(i,j,k);
    }
    if(i%2==0&&j>1&&ok[i][j-1]==false)
    {
        mp[i][j]=a[++k];
        ok[i][j]=true;
        j--;
        put(i,j,k);
    }
    if(i%2==1&&j==r){
        mp[i][j]=a[++k];
        ok[i][j]=true;
        i++;
        put(i,j,k);
    }
    if(i%2==0&&j==1){
        mp[i][j]=a[++k];
        ok[i][j]=true;
        i++;
        put(i,j,k);
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>c>>r;
    int mp[c][r];
    int m=c*r;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i];
        t=a[1];
    }
    sort(a+1,a+m+1,cmp);
    put(1,1,0);
    return 0;
}
