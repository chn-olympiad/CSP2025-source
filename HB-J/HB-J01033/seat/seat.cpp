#include<bits//stdc++.h>
using namespace std;
int m,n,a[100],b[100],f,k=0,w,p=0,e;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>m>>w;
    a[0]=w;
    for(int i=1;i<m*n;i++){
        cin>>f;
        a[i]=f;
    }f=-1;
    for(int i=0;i<m*n;i++){
        for(int j=0;j<m*n;j++){
            if(k<a[j]){
                k=a[j];
                e=j;
            }
        }a[e]=0;
        b[i]=k;
        if(k==w)
            p=i+1;
        k=0;
    }
    if(p%n==0)
        m=p/n;
    else
        m=(p-p%n)/n+1;
    if(m%2==1)
        if(p%n==0)
            n=n;
        else
            n=p%n;
    else
        if(p%n==0)
            n=1;
        else
            n=n-p%n+1;
    cout<<m<<' '<<n;
    return 0;
}
