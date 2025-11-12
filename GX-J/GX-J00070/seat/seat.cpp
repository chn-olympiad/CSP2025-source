#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,q,s,p,l,e;
    int a[10001];
    cin>>n>>m;
    s=n*m;
    for(int i=0;i<=s;i++)
        cin>>a[i];
        p=a[1];
        for(int j=0;j<=s;j++)
        {
            if(a[j]>a[j+1])
            {
                q=a[j];
                a[j]=a[j+1];
                a[j+1]=q;
            }
        }
        for(int x=0;x<=s;x++)
        {
           if(a[x]==p)
                p=x;
        }
           for(int y=0;y<=s;y++)
           {
               l=m/p;
               if(l%2==0)
                e=m/p;
                else
                    e=p/m;
           }
           cout<<e<<" "<<l<<endl;
	return 0;
}
