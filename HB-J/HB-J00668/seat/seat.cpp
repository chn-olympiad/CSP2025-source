#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    vector<int>a;
    int k;
    cin>>n>>m;
    int v=n*m;
    for(int i=0;i<v;i++)
    {
        cin>>k;
        a.push_back(k);
    }
    int x=0,y=1;
    int l=0;
    int s=a[0];
    sort(a.begin(),a.end(),cmp);
    int f;
    for(int i=0;i<v;i++)
    {
        if(a[i]==s)
        {
            f=i+1;
            break;
        }
    }
    for(int i=0;i<v;i++)
    {
        l++;
        if(y%2==0)x--;
        else x++;        
        if((y%2==0&&x==1)||(y%2==1&&x==n))
        {
            if(l==f)
            {
                cout<<y<<' '<<x;
                break;
            }  
            y++;
            l++;
        }
        if(l==f)
        {
            cout<<y<<' '<<x;
            break;
        }    
    }
    return 0;
}