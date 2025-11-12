#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y;
    scanf("%d%d",&x,&y);
    int a[x*y];
    for(int i=0;i<x*y;i++)
        scanf("%d",&a[i]);
    int b=a[0];
    for(int i=x*y-1;i>=0;i--)
        for(int j=1;j<i;j++)
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
    for(int i=1;i<x*y-1;i++)
        if(b<a[i]&&b>a[i+1])
            b=i+1;
    int x1,y1;
    if(b%x>0)
        x1=b/x+1;
    else
        x1=b/x;
    b%=x;
    if((x1-1)%2)
        y1=x-b;
    else
        y1=b;
    cout<<x1<<' '<<y1;
    return 0;
}
