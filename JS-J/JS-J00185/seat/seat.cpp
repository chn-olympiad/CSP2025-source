#include <bits/stdc++.h>
using namespace std;
int maze[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long a,b,c,p=0;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++)
    {
        cin>>maze[i];
        c=maze[1];
    }
    sort(maze+1,maze+1+a*b);
    for(int i=a*b;i>=1;i--)
    {
        if(maze[i]==c)
        {
            p=a*b-i+1;
        }
    }
    long long n=p/a;
    long long m=p%a;
    if(n%2==0&&m!=0)
    {
        cout<<n+1<<" "<<m;
    }
    else if(n%2==0&&m==0)
    {
        cout<<n<<" "<<1;
    }
    else if(n%2==1&&m==0)
    {
        cout<<n<<" "<<a;
    }
    else if(n%2==1&&m!=0)
    {
        cout<<n+1<<" "<<a+1-m;
    }
    return 0;
}
