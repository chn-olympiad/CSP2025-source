#include<bits/stdc++.h>
int l[5];
int n;
int hap=0;
int maps[1000000][4];
int res=0;
using namespace std;
void dfs(int x,int y)
{
    res=max(res,hap);
    for(int i=0;i<=2;i++)
    {
        if(l[i]<n/2){
            hap+=maps[x+1][i];
            l[i]++;
            dfs(x+1,i);
            res=max(res,hap);
            l[i]--;
            hap-=maps[x+1][i];
        }
    }
    res=max(res,hap);
}
int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int times=1;times<=t;times++)
    {
        res=0;
        l[0]=0;
        l[1]=0;
        l[2]=0;
        hap=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            maps[i][0]=a;
            maps[i][1]=b;
            maps[i][2]=c;
        }
        for(int m=0;m<=2;m++){
            l[m]++;
            hap=maps[1][m];
            dfs(1,m);
            l[m]--;
        }
        cout<<res<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}