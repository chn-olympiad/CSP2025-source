#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[500005];
//int p[500005];
//int b1[500005];
//int c1[500005];
int pan(int l,int r)
{
	int he=a[l];
	for(int i = l+1 ; i < r ; i++)
	{
		he=he|a[i];
	}
	return he;
}
/*
int pan2(int l1,r1)
{
	int geshu=0;
	for(int i = l1+1 ; i < r1 ; i++)
	{
		if(b1[i]<b1[i+1])
		{
			if(c1[i]<b1[i+1]) geshu++;
		}
		else
		{
			
		}
	}
}
*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=0;
	int cnt=0;
	int f=0;
	while(l!=r||r!=n)
	{
		r++;
		if(r>n)
		{
			l+=1;
			r=l;
		}
		if(pan(l,r)==k) 
		{
			/*
			bool flag=true;
			for(int i = l ; i <= r ; i++)
			{
				if(!p[i]) p[i]=1;
				else flag=false;
			}
			if(flag) cnt++;
			*/
			cnt++;
			//cout << "Çø¼ä" << cnt << ":" << l << " " << r << endl;
			//b1[++f]=l;
			//c1[f]=r;
		}
	}
	/*
	int l1=1,r1=0;
	while(l1!=r1||r1!=f)
	{
		r1++;
		if(r1>f)
		{
			l1+=1;
			r1=l1;
		}
		
	 } */
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
