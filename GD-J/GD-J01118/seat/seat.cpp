#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;++i)
	{
		scanf("%d",&a[i]);
		if(i==1)s=a[i];
	}
	if(n==1&&m==1){printf("1 1");fclose(stdin);fclose(stdout);return 0;}
	else if(n==1&&m==2)
	{
		if(a[1]>a[2]){printf("1 1");fclose(stdin);fclose(stdout);return 0;}
		else{printf("2 1");fclose(stdin);fclose(stdout);return 0;}
	}
	else if(n==2&&m==1)
	{
		if(a[1]>a[2]){printf("1 1");fclose(stdin);fclose(stdout);return 0;}
		else{printf("1 2");fclose(stdin);fclose(stdout);return 0;}
	}
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;++i)
	{
		if(a[i]==s)
		{
			int l=1,r=1;
			for(l=1;l<=m;++l)
			{
				if(l%2==1)
				{
					for(r=1;r<=n;++r)
					{
						if((l-1)*m+r==i)
						{
							printf("%d %d",l,r);
							fclose(stdin);
							fclose(stdout);
							return 0;
						}
					}
				}
				else
				{
					for(r=n;r>=1;--r)
					{
						if((l-1)*m+(n-r+1)==i)
						{
							printf("%d %d",l,r);
							fclose(stdin);
							fclose(stdout);
							return 0;
						}
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
