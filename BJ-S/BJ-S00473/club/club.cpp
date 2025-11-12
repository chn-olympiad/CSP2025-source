#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],num[4],nn,s2,s3;
int love[20005],cur;
int newa[100005];

void pool()
{
    for(int i=0;i<=n;i++)
    {
        love[newa[i]]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=love[i];j++)
        {
            newa[cur]=i;
            cur++;
        }
    }
}

int toa()
{

    for(int i=0;i<n;i++)
    {
        newa[i]=a[i][1];
    }
    int ans=0;
    for(int i=0;i<nn;i++)
    {
        ans+=newa[i];
    }
    return ans;
}

int tob(int who){
    if(who>=n) return 0;

    int ans=0;
    for(int i=1;i<=2;i++){
        if(num[i]<nn){
            num[i]++;
            ans=max(ans,tob(who+1)+a[who][i]);
            num[i]--;
        }
    }
    return ans;
}

int dfs(int who){
    if(who>=n) return 0;

    int ans=0;
    for(int i=1;i<=3;i++){
        if(num[i]<nn){
            num[i]++;

            ans=max(ans,dfs(who+1)+a[who][i]);
            //cout <<num[1]<<num[2]<<num[3]<<' '<<ans<<endl;
            num[i]--;
        }
    }
    return ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        nn=n/2;
        //cout << nn<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            s2+=a[i][2];
            s3+=a[i][3];
        }
        //memset(mem,-1,sizeof(mem));
        memset(num,0,sizeof(num));
        if(s2==0 && s3==0) cout << toa() <<endl;
        else if(s3==0) cout << tob(0)<<endl;
        else cout << dfs(0)<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
