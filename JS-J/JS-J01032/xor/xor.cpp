#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int n,k;
unordered_map<int,unordered_map<int,int>> key;
void dfs(int X,int Y)
{
    if(X==Y){
        return;
    }
    else{
        dfs(X,(X+Y)/2);
        dfs((X+Y)/2+1,Y);
        key[X][Y]=(key[X][(X+Y)/2]^key[(X+Y)/2][Y]);
    }
}
int get_num(int L,int R)
{
    if(key.find(L)!=key.end())
    {
        if(key[L].find(R)!=key[L].end()){
            return key[L][R];
        }
    }
    key[L][R]=(get_num(L,(L+R)/2)^get_num((L+R)/2+1,R));
    return key[L][R];
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        key[i][i]=a[i];
    }
    dfs(1,n);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int cnt=0;
        bool f=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(get_num(i,j)==k)
                {
                    cnt++;
                    if(cnt==mid)
                    {
                        f=1;
                        i=j+1;
                        break;
                    }
                    i=j+1;
                    break;
                }
            }
            if(f)break;
        }
        if(f)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%d",ans+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

