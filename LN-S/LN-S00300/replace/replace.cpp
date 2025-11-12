#include<bits/stdc++.h>
using namespace std;
vector<char> a[200005];
vector<char> b[200005];
char aa[200005];
char bb[200005];
int n,q,p,ans;
inline void read(int i)
{
    char ch=getchar();
    while(ch>='a'&&ch<='z')
    {
        a[i].push_back(ch);
        ch=getchar();
    }
    ch=getchar();
    while(ch>='a'&&ch<='z')
    {
        b[i].push_back(ch);
        ch=getchar();
    }
    return;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
   scanf("%d%d",&n,&q);
   char ch=getchar();
   for(int i=1;i<=n;i++)
   {
       read(i);
   }
   for(int i=1;i<=q;i++)
   {
       ans=0;
       scanf("%s",aa);
       scanf("%s",bb);
       int lena=strlen(aa);
       int lenb=strlen(bb);
       if(lena!=lenb)
       {
           printf("0\n");
           continue;
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=0;j<=lena;j++)
           {
               if(aa[j]==a[i][0])
               {
                   p=0;
                   for(int z=1;z<a[i].size();z++)
                   {
                       char aaa=aa[z];
                       char bbb=a[i][z];
                       if(aaa!=bbb&&p==0)
                       {
                           p=1;
                       }
                   }
                   if(p==0)
                   {
                       for(int z=0;z<j;z++)
                       {
                           if(aa[z]!=bb[z]&&p==0)
                           {
                               p=1;
                           }
                       }
                       for(int z=0;z<a[i].size();z++)
                       {
                           char aaa=b[i][z];
                           char bbb=bb[z+j];
                           if(aaa!=bbb&&p==0)
                            p=1;
                       }
                       for(int z=z+j;z<lena;z++)
                       {
                           if(aa[z]!=bb[z]&&p==0)
                           {
                               p=1;
                           }
                       }
                   }
                   if(p==0)
                   {
                       ans++;
                   }
               }
           }
       }
       printf("%d\n",ans);
   }
   return 0;
}
