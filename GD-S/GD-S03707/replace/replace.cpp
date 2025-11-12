#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+5,L=5e6+5;
int n,q,pos[N][3];
char s[L],t1[L],t2[L];
int qz[N],hz[N],ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+pos[i-1][2]+1);
		pos[i][1]=strlen(s+1);
		scanf("%s",s+pos[i][1]+1);
		pos[i][2]=strlen(s+1);
	}
	while(q--)
	{
		scanf("%s%s",t1+1,t2+1);
		int ln=strlen(t1+1),ln1=strlen(t2+1);
		qz[0]=hz[ln+1]=0;
		if(ln!=ln1)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=ln;i++)
		{
			qz[i]=qz[i-1];
			if(!qz[i])
			{
				if(t1[i]!=t2[i]) qz[i]=1;
			}
		}
		for(int i=ln;i>=1;i--)
		{
			hz[i]=hz[i+1];
			if(!hz[i])
			{
				if(t1[i]!=t2[i]) hz[i]=1;
			}
		}
		ans=0;
		for(int i=1;i<=ln;i++)
		{
			if(qz[i-1]) break;
			for(int j=1;j<=n;j++)
			{
				int ed=i+pos[j][1]-pos[j-1][2]-1;
				if(ed>ln||hz[ed+1]) continue;
				bool bz=0;
				int gs=0;
//				printf("%d %d\n",i,j);
				for(int k=i;k<=ed;k++)
				{
					gs++;
					if(t1[k]!=s[pos[j-1][2]+gs])
					{
						bz=1;
						break;
					}
					if(t2[k]!=s[pos[j][1]+gs])
					{
						bz=1;
						break;
					}
				}
				if(!bz) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
