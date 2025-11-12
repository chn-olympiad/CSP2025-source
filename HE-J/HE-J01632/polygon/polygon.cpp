#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int answer=0;
int add(int l,int r)
{
    int susu=0;
    for(int jjjj=l;jjjj<=r;jjjj++)
    {
        susu+=a[jjjj];
    }
    return susu;
}
int maax(int l,int r)
{
    int maxxx=-1;
    for(int irr=l;irr<=r;irr++)
    {
        if(a[irr]>maxxx)
        {
            maxxx=a[irr];
        }
    }
    return maxxx;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int nu=3;nu<=n;nu++)
    {
        for(int l=1;l<=n;l++)
        {
            for(int j=l;j<=n;j++)
            {
                if(j-l==nu&&add(l,j)>maax(l,j)*2)
                {
                    answer+=1;
                }
            }
        }
    }
    cout<<answer;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
