#include<bits/stdc++.h>
using namespace std;
int p[100005],s[100005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,id,o;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
        p[i]=s[i];
    }
    o=s[1];
    sort(p+1,p+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(s[1]==p[i]) id=i;
    }
    if(id%n!=0)
    c=id/n+1;
    else
    c=id/n;
    if(id%n!=0)
    {
        r=id%n;
    }
    else
    {
        r=n;
    }
    if(c%2==0)
    {
        for(int i=c*n;i>=c*n-n;i--)
        {
            if(o=p[i]) r=i;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
//2 2
//99 100 97 98
