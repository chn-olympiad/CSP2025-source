#include <bits/stdc++.h>
#include <bits/c++config.h>
#include <bits/memoryfwd.h>
using namespace std;
bool b(int x,int y)
{
    return x>y;
}
int n,m,a[105],c,r,w,s[105];
int main()
{
    freopen ("seat.in"," r",stdin);
    freopen ("seat.out"," w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=(n*m);i++)
    {
        std::cin>>s[i];
        a[i]=s[i];
    }
    sort(s+1,s+n+1,b);
    for(int i=1;i<=(n*m);i++)
    {
        if(s[i]==a[1])
        {
            w=i;
            break;
        }
    }
    if(w%m==0)
    {
       c=w/m;
    }
    else{
        c=w/m+1;
    }

    if(w%m>0&&(w/m)%2==0)
    {
        r=w-(w/m*m);
    }
    else if(w%m==0&&(w/m)%2==1){
        r=w-(w/n*n);
    }
    else{
    	r=n-(w-((w/n)*n));
	}
    std::cout<<c+1<<' '<<r;
    return 0;
}
