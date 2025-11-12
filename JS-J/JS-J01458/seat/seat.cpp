#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    char w='d';
    int cnt=0,x=1,y=1;
    while(cnt<=n*m)
    {
        cnt++;
        if(a[cnt]==s)
        {
            cout<<y<<' '<<x;
            return 0;
        }
        if(w=='d')
        {
            if(x<n)
            {
                x++;
            }
            else
            {
                w='u';
                y++;
            }
        }
        else
        {
            if(x>1)
            {
                x--;
            }
            else
            {
                w='d';
                y++;
            }
        }
    }
    return 0;
}
