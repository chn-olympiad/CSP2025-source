#include <bits/stdc++.h>
using namespace std;
bool cmp(int q,int e)
{
    if(q>e) return true;
    else return false;
}
int n,m,k,d=0,x=0,y=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++) cin>>a[i];
    k=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==k)
        {
            cout<<x+1<<" "<<y+1;
            break;
        }
        else if(d==0&&y+1<n) y++;
        else if(d==1&&y-1>=0) y--;
        else if(d==0&&y+1>=n)
        {
            x++;
            d=1;
        }
        else if(d==1&&y-1<0)
        {
            x++;
            d=0;
        }
    }
	return 0;
}
