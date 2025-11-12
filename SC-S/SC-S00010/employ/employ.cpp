#include<cstdio>
using namespace std;
int  naixin[501];
char f[501];
int n,m;
int fangan[501];
int biaoji[501];
long long int jishu=0;
int jiren=0;
void A(int a){
	if(a==n+1)
	{
		jiren=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i-1]=='0')
			{
				jiren++;
			}
			else{
				if(naixin[fangan[i]]-jiren<=0)
				{
					jiren++;
				}
			
			}
			
		}
		if((n-jiren)==m)
		jishu++;
		
	}
	else{
		for(int i=1;i<=n;i++)
		{
			if(biaoji[i]!=1)
			{
				fangan[a]=i;
				a++;
				biaoji[i]=1;
				A(a);
				a--;
				biaoji[i]=0;
			}
		}
	}
	
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",f);
//	printf("%c",f[0]);
	for(int i=1;i<=n;i++)
	scanf("%d",&naixin[i]);
	
	
	A(1);
	printf("%d",jishu%998244353); 
	return 0;
}