#include<iostream>
#include<algorithm>
using namespace std;
int dfs(int a,int s,int q);//a:dang qian zhi suo yin s:zui da zhi q: he
int l[5001];
int t[5001];
int z=0,a;
long long n=0;
int main()
{
    cin>>a;
    int t[a];
    for(int i=0;i<a;i++)
    {
        cin>>t[i];
    }
    sort(t,t+a);
    for(int i=a-1;i>-1;i--)
    {
        n+=dfs(i,i,i);
        n%=998244353;
    }
    cout<<n;
    return 0;
}
int dfs(int a,int s,int q)
{
    int w=0;
    for(int i=a-1;i>0;i--)
    {
        l[z]=t[i];
        z++;
        w+=dfs(i,s,q+i);
        z--;
    }
    if(z>=3&&s*2<q)
    {
        w++;
    }
    w%=998244353;
    return w;
}
