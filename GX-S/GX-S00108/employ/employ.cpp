#include<bits/stdc++.h>
using namespace std;

const int N=100100,MOD=998244353;
inline int rd()
{
	int x=0,f=1;
	char c=getchar();
	while( !isdigit(c) ) f=c=='-'?-1:1,c=getchar();
	while( isdigit(c) ) x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m,a[N],ans;
string s;
bool pdA;
bool pd()
{
    int t=0,p=0;
    for( int i=1;i<=n;i++ )
    {
        if( s[i-1]=='1' ) t++;
        if( a[i]<=t ) t++;
        else p++;
    }
    return p>=m;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	getline(cin,s);
	for( int i=1;i<=n;i++ ) a[i]=rd();
	for( int i=0;i<n;i++ )
		if( s[i]=='0' )
		{
			pdA=true; break;
		}
	if( !pdA )
	{
		sort(a+1,a+n+1,greater<int>());
		int tot=0;
		for( int i=1;i<=n&&a[i]!=0;i++ )
            if( a[i]!=0 ) tot++;
        n=tot;
		int t=0,num=1;
		for( int i=1;i<=n;i++ )
			if( a[i]>t )
			{
				t++; num=num*t%MOD;
			}
		printf("%d",num);
	}
	while(next_permutation(a+1,a+n+1))
        if( pd() ) ans++;
    printf("%d",ans);
	return 0;
}


