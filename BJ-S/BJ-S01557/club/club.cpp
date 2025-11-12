#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;
}a[505];
/*int getans4()
{
    //面向结果大法好，只得五分也是宝
    int a,b,c;
    int d,e,f;
    int g,h,i;
    int j,k,l;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    int ans=-1;
    ans=max(a+d+h+l,max(a+d+i+k,max(a+d+h+k,max(a+d+i+l,ans))));
    ans=max(a+g+e+k,max(a+g+f+l,max(a+g+e+l,max(a+g+f+k,ans))));
    ans=max(a+j+e+h,max(a+j+f+i,max(a+j+e+i,max(a+j+f+h,ans))));
    ans=max(d+g+b+k,max(d+g+c+l,max(d+g+b+l,max(d+g+c+k,ans))));
    ans=max(d+j+b+h,max(d+j+c+i,max(d+j+b+i,max(d+j+c+h,ans))));
    ans=max(g+j+b+e,max(g+j+c+f,max(g+j+b+f,max(g+j+c+e,ans))));
    return ans;
}*/
int ans=-1;
void dfs(int n,int id,int an,int bn,int cn,int scr)
{
    if(id==n)
    {
        ans=max(ans,scr);
        return;
    }
    if(an+1<=n/2)
        dfs(n,id+1,an+1,bn,cn,scr+a[id+1].a);
    if(bn+1<=n/2)
        dfs(n,id+1,an,bn+1,cn,scr+a[id+1].b);
    if(cn+1<=n/2)
        dfs(n,id+1,an,bn,cn+1,scr+a[id+1].c);
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--) //n<=10
    {
        int n;
        cin>>n;
        /*
        if(n==2)
        {
            int ans=-1;
            int a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            ans=max(ans,max(a+e,max(a+f,max(b+d,max(b+f,max(c+d,c+e))))));
            cout<<ans<<endl;
        }
        else if(n==4)
        {
            cout<<getans4()<<endl;
        }
        else*/
        //{
            ans=-1;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i].a>>a[i].b>>a[i].c;
            }
            dfs(n,0,0,0,0,0);
            cout<<ans<<endl;
        //}
    }
    return 0;
}
