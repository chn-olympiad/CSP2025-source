#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out", "w",stdout);
    int n,m,b,c=1,a;
    cin>>n>>m>>a;
    b=a;
    for(int i=1;i<=n*m-1;i++)
    {
        cin>>a;
        if(a>b)c++;
    }
    if(c%(n*2)==0)cout<<c/n<<" "<<1;
    else if(c%(n*2)>0&&c%(n*2)<=n)cout<<(c-c%(n*2))/n+1<<" "<<c%(n*2);
    else if(c%(n*2)>n)cout<<(c-c%(n*2))/n+2<<" "<<n*2-c%(n*2)+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
