#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[N],n,m;
bool cmp(int a,int b)
{
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            int r=(i+n-1)/n,c=i%n;
            cout<<r<<' ';
            if(c==0)
                c=n;
            if(r&1)
                cout<<c<<endl;
            else
                cout<<n+1-c<<endl;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}