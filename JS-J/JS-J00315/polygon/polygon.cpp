#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {return a>b;}
int tp,n,a[5005],ans,mult[5005];
// int Cs[5005][5005];
int Cres[5005][5005];
long long C(int i,int j)
{
    if(Cres[i][j]!=-1) return Cres[i][j];
    if(j==1) return Cres[i][1]=i;
    if(i==j) return Cres[i][j]=1;
    return Cres[i][j]=((C(i-1,j-1)+C(i-1,j))%998244353);
}
// long long dfs(int req,int from)
// {
//     if(req<=0) return Cs[n-from+1];
//     if(from==n+1&&req>0)
//     else return
// }
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(Cres,-1,sizeof(Cres));
    cin>>n; //cout<<n<<endl;
    for(int i=1;i<=n;i++)
        {cin>>a[i]; tp=max(tp,a[i]);}
    sort(a+1,a+n+1,cmp);
    if(n<=20)
    {
        long long maximum=(1<<n)-1;
        //for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
        for(long long i=1;i<=maximum;i++)
        {
            int k=i,idx=n,length=0,sum=0,selectend=0;
            //cout<<"New selecting indexed: "<<k<<" started"<<endl;
            while(k!=0)
            {
                while(k%2==0) k/=2,idx--;
                if(k%2==1)
                {
                    //cout<<"Position "<<idx<<" selected"<<endl;
                    selectend=max(selectend,a[idx]);
                    sum+=a[idx]; k/=2; length++; idx--;
                }
            }
            //cout<<"Total selected "<<length<<" elements. Suming "<<sum<<" while having a peak which is "<<selectend<<endl;
            if(length<3) continue;
            else if(sum<=selectend*2) continue;
            else ans++;
        }
        cout<<ans<<endl; return 0;
    }
    else if(tp==1)
    {
        for(int i=3;i<=n;i++)
            ans=(ans+C(n,i))%998244353;
        cout<<ans<<endl; return 0;
    }
    // else if(n<=500)
    // {
    //     for(int i=1;i<=n;i++)
    //     {
    //         ans+=dfs(a[i]*2,i+1);
    //     }
    // }
}
