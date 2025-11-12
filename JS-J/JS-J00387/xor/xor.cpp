#include<bits/stdc++.h>
using namespace std;
long long m,n,sum,num;
int po;
int a[22],b[22],c[500001],s[500001],v[500001];
int er(long long x)
{
    int i=1;
    while(x!=0)
    {
        a[i]=x%2;
        i++;
        x/=2;
    }
    po=i-1;
    return 0;
}
int xo(int k,int f)
{
    int si=0;
    er(k);
    for(int i=1;i<=po;i++)
    {
        b[i]=a[i];
    }
    int d=po;
    er(f);
    for(int i=1;i<=max(d,po);i++)
    {
        if(a[i]==b[i])
        {
            c[i]=0;
        }
        else
        {
            c[i]=1;
        }
    }
    for(int i=1;i<=max(d,po);i++)
    {
        if(c[i]==1)
        {
            si+=pow(2,i-1);
        }
    }
    return si;
}
int main(){
    int q=0;
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        if(c[i]!=-1)
        {
            sum=c[i];
            for(int j=i+1;j<=m;j++)
            {
                if(sum==n)
                {
                    num++;
                    break;
                }
                else
                {
                    sum=xo(sum,c[j]);
                    s[q]=j;
                    v[q]=c[j];
                    q++;
                    c[j]=-1;
                    if(sum==n)
                    {
                        num++;
                        break;
                    }
                }
            }
            if(sum!=n)
            {
                for(int i=0;i<1;i++)
                {
                    c[s[i]]=v[i];
                    for(int j=0;j<q;j++)
                    {
                        v[j]=0;
                        s[j]=0;
                    }
                }
            }
            sum=0;
        }
    }
    if(c[m]==n)
    {
        num++;
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
