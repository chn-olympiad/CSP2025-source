#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N=500050;
int n,k,Ans=0;
string num[N],f;
string check(string x)
{
    while(x.length()>1 && x[x.length()-1]=='0')
        x=x.substr(0,x.length()-1);
    return x;
}
string my_change(int x)
{
    if(x==0)
        return "0";
    string ans="";
    while(x)
    {
        ans+=x%2+'0';
        x/=2;
    }
    return check(ans);
}
string yh(string a,string b)
{
    string ans="";
    int lena=a.length(),lenb=b.length();
    if(lena<lenb)
    {
        int t=lena;
        lena=lenb;
        lenb=t;
        string temp=a;
        a=b;
        b=temp;
    }
    for(int i=0;i<lena || i<lenb;i++)
    {
        if(i<lenb)
            ans+=(a[i]!=b[i])+'0';
        else
            ans+=(a[i]!='0')+'0';
    }
    return check(ans);
}
void dfs(int step,int sum)
{
    if(step==n+1)
    {
        Ans==max(Ans,sum);
        return ;
    }
    Ans=max(Ans,sum);
    string h="0";
    for(int i=step;i<=n;i++)
    {
        h=yh(h,num[i]);

        if(h==f)
            dfs(i+1,sum+1);
    }
    if(num[step]==h)
        dfs(step+1,sum+1);
    else
        dfs(step+1,sum);
    return ;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%d %d",&n,&k);
    f=my_change(k);

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        num[i]=my_change(x);
    //    cout<<num[i]<<"\n";
    }
    /*
    for(int i=1;i<=n;i++)
        cout<<num[i]<<" ";
    cout<<endl;
    */
    dfs(1,0);
    cout<<Ans;

    return 0;
}
