#include<cstdio>
#include<iostream>
using namespace std;
int f[10001][4];
int fangfa[10001];
int fashu;
int a1,a2;
int jieshu;
int answer;

void A(int a);
void B(int n,int a);
int check(int a);

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		A(i);
	}
	return 0;
}

void A(int a){
	int n;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	a1=-1;
    a2=0;	
	B(n,1);
}

void B(int n,int a){
	
    if(a==n+1)
    {
    	int manyi=0;
    	for(int i=1;i<=n;i++)
    	{
    		manyi+=f[i][fangfa[i]];
		}
		a2=manyi;
		if(a2>a1)
		a1=a2;
		fashu++;
		if(jieshu==n)
		printf("%d",a1);
	}
	
	if(a!=n+1){
		for(int i=1;i<=3;i++)
		{
			if(a==1)
			{
				jieshu=0;
				fashu==0;
			}
			
			fangfa[a]=i;
			a++;
			if(i==3)
			jieshu++;
			B(n,a);
			a--;
			if(i==3)
			jieshu--;
		}
	}
	
}

int check(int a){
	int jishu[4];
	for(int i=1;i<=3;i++)
	jishu[i]=0;
	for(int i=1;i<a;i++)
	{
		jishu[fangfa[i]]++;
	}
	for(int i=1;i<=3;i++)
	{
		if(jishu[i]>a/2)
		return -1;
	}
	return 1; 
}
