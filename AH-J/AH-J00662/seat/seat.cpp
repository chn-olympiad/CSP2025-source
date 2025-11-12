#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    if(a>b)return true;
    else return false;
}
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}},temp[11][11];
bool oj[11][11];
int n,m;
void dfs(vector<int >&a,int R,int i,int &x,int &y)
{
    if(a[i]==R)return ;
    else
    {
        oj[x][y]=true;
        for(int j=0;j<4;++j)
        {
            int dx=x+d[j][0];
            int dy=y+d[j][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&oj[dx][dy]==false)
            {
                x=dx;
                y=dy;
                dfs(a,R,i+1,x,y);
                return ;
            }
        }
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int >a(n*m);
    for(int i=0;i<n*m;++i)
        cin >> a[i];
    int R=a[0];
    sort(a.begin(),a.end(),cmp);
    int x=0,y=0;
    dfs(a,R,0,x,y);
    cout << y+1 <<' ' << x+1;
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
