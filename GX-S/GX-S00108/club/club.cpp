#include<bits/stdc++.h>
using namespace std;

const int N=200010;
inline int rd()
{
    int x=0,f=1;
    char c=getchar();
    while( !isdigit(c) ) f=c=='-'?-1:1,c=getchar();
    while( isdigit(c) ) x=x*10+c-'0',c=getchar();
    return x*f;
}
struct stu
{
    int x,y,z;
}a[N];
int T,n,c[4],d[N][4],di[N][4];       //[i] choose 1,2,3
bool bo[N],pdA;
int ge( int i,int x )
{
    if( x==1 ) return a[i].x;
    if( x==2 ) return a[i].y;
    return a[i].z;
}
bool cmp( stu x,stu y )
{
	return x.x>y.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=rd();
    while( T-- )
    {
        n=rd();
        for( int i=1;i<=n;i++ )
        {
            a[i].x=rd(),a[i].y=rd(),a[i].z=rd();
            if( a[i].y!=0||a[i].z!=0 ) pdA=true;
        }
        if( !pdA )
        {
			sort(a+1,a+n+1,cmp);
			for( int i=1;i<=n/2;i++ ) ans+=a[i];
			printf("%d",ans); continue;
		}
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        memset(di,0,sizeof(di)); memset(bo,false,sizeof(bo));
        int ans=0;
        for( int i=1;i<=n;i++ )
        {
            if( a[i].x>a[i].y&&a[i].x>a[i].z )
            {
                d[i][1]=1;
                if( a[i].y>a[i].z ) d[i][2]=2,d[i][3]=3;
                else d[i][2]=3,d[i][3]=2;

            }
            if( a[i].y>a[i].x&&a[i].y>a[i].z )
            {
                d[i][1]=2;
                if( a[i].x>a[i].z ) d[i][2]=1,d[i][3]=3;
                else d[i][2]=3,d[i][3]=1;
            }
            if( a[i].z>a[i].x&&a[i].z>a[i].y )
            {
                d[i][1]=3;
                if( a[i].x>a[i].y ) d[i][2]=1,d[i][3]=2;
                else d[i][2]=2,d[i][3]=1;
            }
            di[i][d[i][1]]=ge(i,d[i][1])-ge(i,d[i][2]);
        }
        for( int i=1;i<=n;i++ )
        {
            int x=d[i][1],y=d[i][2],z=d[i][3];
            if( c[x]<n/2 )
            {
                ans+=ge(i,x),c[x]++;
            }
            else
            {
                int num=di[i][d[i][1]],x0=0;
                for( int j=i-1;j>=1;j-- )
                    if( di[j][d[i][1]]<num&&di[j][d[i][1]]!=0&&!bo[j] )
                        x0=j,num=di[j][d[i][1]];
                if( x0==0 )
                {
                    ans+=ge(i,y),c[y]++,bo[i]=true;
                    continue;
                }
                ans=ans+ge(i,x)-num; c[d[x0][2]]++;
                bo[x0]=true;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

