#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
const int N=1005;
int n,q;
string s[N],b[N];
ull hs[N][N*2],hb[N][N*2];
ull hx[N*2],hy[N*2];
ull p[N],P=13331;
int ans=0;
int main()
{
   freopen("replace2.in","r",stdin);
   freopen("replace.out","w",stdout);
   scanf("%d%d",&n,&q);
   getchar();
   for(int i=1;i<=n;i++)
   {
     cin>>s[i]>>b[i];
     int ls=s[i].size();
     hs[i][0]=s[i][0]-'a';
     hb[i][0]=b[i][0]-'a';
     for(int j=1;j<ls;j++)
     {
       hs[i][j]=hs[i][j-1]*P+s[i][j]-'a';
       hb[i][j]=hb[i][j-1]*P+b[i][j]-'a';
     }
   }
   p[0]=1;
   for(int i=1;i<=1000;i++)
     p[i]=p[i-1]*P;
   for(int i=1;i<=q;i++)
   {
     ans=0;
     string tx,ty;
     cin>>tx>>ty;
     memset(hx,0,sizeof(hx));
     memset(hy,0,sizeof(hy));
     int lt=tx.size();
     hx[0]=tx[0]-'a';
     hy[0]=ty[0]-'a';
     for(int j=1;j<lt;j++)
     {
       hx[j]=hx[j-1]*P+tx[j]-'a';
       hy[j]=hy[j-1]*P+ty[j]-'a';
     }
     for(int j=1;j<=n;j++)
     {
       int ls=s[j].size();
       if(ls>lt) continue;
       ull tms=hs[j][ls-1],tmb=hb[j][ls-1];
       for(int k=0;k<lt;k++)
       {
         if(k+ls-1==lt) break;
         if(tx[k]==s[j][0] && ty[k]==b[j][0])
         {
            ull tmx=0,tmy=0;
            if(k==0) {tmx=hx[ls-1]; tmy=hy[ls-1];}
            else {tmx=hx[k+ls-1]-hx[k-1]*p[ls]; tmy=hy[k+ls-1]-hy[k-1]*p[ls];}
            if(tmx==0) continue;
            if(tmx==tms && tmy==tmb) {ans++; continue;}
         }
       }
     }
     cout<<ans<<endl;
   }
   return 0;
}

