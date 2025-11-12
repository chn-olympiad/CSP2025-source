#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k,ans=0;
int a[N];
int m[N][N];

int xor(int a,int b)
{
    int a1=a,b1=b,c=0,len=0;
    string a2="",b2="";
    while(a1!=0 && b1!=0)
    {
        a>>1;
        b>>1;
        len++;
    }
    a1=a;b1=b;
    for(int i=0;i<len;i++)
    {
        a2=char((a1%2)+'0')+a2;
        b2=char((b1%2)+'0')+b2;
        a1>>1;
        b1>>1;
    }
    for(int i=0;i<len;i++)
    {
        c<<1;
        if(a2[i]!=b2[i]) c+=1;
    }
    return c;
}

int main(void)
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[i][i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            m[i][j]=xor(m[i][j-1],m[j][j]);
            if(m[i][j]==k) ans++;
        }
    }
    cout<<ans;
    return 0;
}
