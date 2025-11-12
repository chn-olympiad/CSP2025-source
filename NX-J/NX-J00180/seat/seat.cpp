#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m,c;
int a[105],b[105];
//int seat[15][15];
//bool vis[15][15];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    c=a[1];
    sort(b+1,b+nm+1,cmp);
    int pos=1;
    while(c!=b[pos])
    {
        pos++;
    }

    int impos;
    int unpos=pos%n;
    if(unpos==0)impos=pos/n;
    else impos=pos/n+1;
    //cout<<impos<<' '<<unpos;

    if(impos%2==0) cout<<impos<<' '<<n/2+n/2+1-unpos;
    else cout<<impos<<' '<<pos-n*(impos-1);

    return 0;
}

