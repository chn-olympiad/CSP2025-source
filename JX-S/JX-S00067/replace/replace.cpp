#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0,b11[200020],b22[200020];
string s1[200020],s2[200020],a1,a2;
bool pds1(int fr,int to,int k)
{
    if((to-fr+1)!=(s1[k].length()-b22[k]-b11[k]))return false;
    for(int i=fr;i<=to;i++)
        if(a1[i]!=s1[k][i-fr+b11[k]])return false;
    return true;
}
bool pds2(int fr,int to,int k)
{
    if((to-fr+1)!=(s2[k].length()-b22[k]-b11[k]))return false;
    for(int i=fr;i<=to;i++)
        if(a2[i]!=s2[k][i-fr+b11[k]])return false;
    return true;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];
        cin>>s2[i];
        int l1=s1[i].length(),l2=s2[i].length();
        b11[i]=0,b22[i]=0;
        while(s1[i][b11[i]]==s2[i][b11[i]])b11[i]++;
        while(s1[i][l1-b22[i]-1]==s2[i][l2-b22[i]-1])b22[i]++;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>a1;
        cin>>a2;
        int b1=0,b2=0,l1=a1.length(),l2=a2.length();
        while(a1[b1]==a2[b1])b1++;
        while(a1[l1-b2-1]==a2[l2-b2-1])b2++;
        ans=0;
        for(int j=1;j<=n;j++)
            if(pds1(b1,l1-b2-1,j)&&pds2(b1,l2-b2-1,j))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
