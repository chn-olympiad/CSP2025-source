#include <bits/stdc++.h>
using namespace std;

int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int j=n*m;
    for(int i=0;i<j;++i)
    {
        cin>>a[i];
    }
	int g=a[0];
    int o=1;
    for(int i=1;i<j;i++)
    {
        if(a[i]>g)
        {
            o++;
        }
    }
    int c,r;
    if(o%m==0)
    {
        c=o/m;
        if(c%2==1)
            r=n;
        else
            r=1;

    }
    else
    {
        c=o/m+1;
        if(c%2==1)
            r=o%n;
        else
            r=n-o%n+1;
    }
    cout<<c<<" "<<r<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;

}
