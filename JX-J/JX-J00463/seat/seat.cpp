#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[105];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }

    int temp_R=a[1],temp_i=1;

    sort(a+1,a+n*m+1,cmp);

    for(int i=1;i<=n*m;i++){
        if(a[i]==temp_R) temp_i=i;
    }

    int c=1,r=1;
    c=(temp_i-1)/n+1;
    r=temp_i%n;
    if(r==0) r=n;
    else if(r%2==0) r=n+1-r;

    cout << c << ' ' << r;


    return 0;
}
