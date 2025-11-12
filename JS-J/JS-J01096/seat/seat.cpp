#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,s[110]={},numall,seat[21][11],cou=1;
    cin>>n>>m;
    numall=n*m;
    for(int i=1;i<=numall;i++)
        scanf("%d",&s[i]);
    a=s[1];
    for(int i=1;i<numall;i++)
        for(int j=i+1;j<=numall;j++)
        if(s[i]<s[j]) swap(s[i],s[j]);
    for(int j=1;j<=m/2;j++)
    for(int i=1;i<=n*2;i++)
    {
        seat[i][j]=s[cou++];
        if(seat[i][j]==a)
        {
            if(i>n) {cout<<2*j<<' '<<2*n-i+1; fclose(stdin); fclose(stdout); return 0;}
            else {cout<<2*j-1<<' '<<i; fclose(stdin); fclose(stdout); return 0;}
        }
    }
    for(int i=1;i<=n;i++) if(s[i+n*m-n]==a) {cout<<m<<' '<<i; fclose(stdin); fclose(stdout); return 0;}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
