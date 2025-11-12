#include<bits/stdc++.h>
using namespace std;
struct A
{
	int jz,h;
}
a[10010];
struct B
{
	int jz,h;
}
b[10010];
struct C
{
	int jz,h;
}
c[10010];
bool cmpa(A x,A y)
{
	return x.jz>y.jz;
}
bool cmpb(B x,B y)
{
	return x.jz>y.jz;
}
bool cmpc(C x,C y)
{
	return x.jz>y.jz;
}
int t,n,bh[10010];
long long sum=0,ans=0;
int main()
{   //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    scanf("%d",t);
    
    for(int i=1;i<=t;i++)
    {   sum=0;
    	scanf("%d",n);
    	for(int j=1;j<=n;j++)
    	   {
		   scanf("%d,%d,%d",a[j].jz,b[j].jz,c[j].jz);
    	   	
		   }
		sort(a+1,a+1+n,cmpa);
		sort(b+1,b+1+n,cmpb);
		sort(c+1,c+1+n,cmpc);
		int r=n,ja=1,jb=1,jc=1;
		while(r)
		{
			if(a[ja].jz>=b[jb].jz&&a[ja].jz>=c[jc].jz&&ja<=n/2&&bh[a[ja].h]){
				sum+=a[ja].jz;
				bh[a[ja].h]=1;
				ja++;
			}
			else if(b[jb].jz>=c[jc].jz&&jb<=n/2&&bh[b[jb].h])
			{
				sum+=b[jb].jz;
				bh[b[jb].h]=1;
				jb++;
			}
			else  if(jc<=n/2&&bh[c[jc].h]){
				sum+=c[jc].jz;
				bh[c[jc].h]=1;
				jc++;
			}
			r--;
		}
		cout<<sum;
		
	}
	return 0;
}