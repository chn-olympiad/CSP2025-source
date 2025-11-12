#include <iostream>
#include <cstdlib>
using namespace std;
int n,k,a[500002],f[500002][2],fi=1,fn;
void calc();
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i,curocc=0,ans=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    calc();
    fn=fi-1;
    for(i=1;i<=fn;i++)
        if(f[i][0]>curocc)
        {
            curocc=f[i][1];
            ans++;
        }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
void calc()
{
    int l,r,i,res=0;
    for(r=1;r<=n;r++)
    {
        res=0;
        for(i=1;i<=r;i++)
            res^=a[i];
        for(l=1;l<=r;l++)
        {
            if(res==k)
            {
                f[fi][0]=l;
                f[fi++][1]=r;
            }
            res^=a[l];
        }
    }
    return ;
}
