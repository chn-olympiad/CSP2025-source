#include<bits/stdc++.h>
using namespace std;
int t,n,m,i,j,k,l,a[10000][3],w,w1,f1,f2,b[10000];
int s[3];
void wu(int i,int j,int w)
{
    if(i==n){
        if(w1<=w) w1=w;
        return ;
    }
    if(s[j]<(n/2)){
            s[j]++;
        wu(i+1,1,w+=a[i][j]);
        w-=a[i][j];
            s[j]--;
            if(j<3)
        wu(i,j+1,w);
    }
    else if(s[j]==(n/2)&&j<3)
    {
    wu(i,j+1,w);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        w1=0;
        cin>>n;
        f1=f2=1;
        for(i=0;i<n;i++)
        for(j=1;j<=3;j++)
        {
            cin>>a[i][j];
            if(a[i][2]!=0) f1=0;
            if(a[i][3]!=0) f2=0;
            b[i]=a[i][1];
        }
        if(f1==1&&f2==1){
            sort(b,b+n);
            for(i=n-1;i>=n/2;i--)
            {
                w1+=b[i];
            }
        }
       else wu(0,1,0);
        cout<<w1;
    }
    return 0;
}
