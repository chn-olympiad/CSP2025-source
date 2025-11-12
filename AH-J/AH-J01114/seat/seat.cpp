#include<bits/stdc++.h>
using namespace std;
int grade[101];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grade[i*n+j];
        }
    }
    int r=grade[0],d=0;
    sort(grade,grade+n*m,cmp);
    while(grade[d]!=r) d++;
    d++;
    if(d%n==0)
    {
        if(d/n%2==1) cout<<d/n<<' '<<n;
        else cout<<d/n<<' '<<1;
    }
    else
    {
        if((d/n+1)%2==1) cout<<d/n+1<<' '<<d%n;
        else cout<<d/n+1<<' '<<n-d%n+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
