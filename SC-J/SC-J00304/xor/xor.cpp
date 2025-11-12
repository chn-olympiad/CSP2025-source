#include<fstream>
#include<iostream>
using namespace std;
bool fun(int s1,int o1,int s2,int o2)
{
	if(s1<=o1&&o1<s2&&s2<=o2) return true;
	if(s2<=o2&&o2<s1&&s1<=o1) return true;
	return false;
}
int fun2(int a,int b)
{
	bool a2[20],b2[20],c2[20];
	int c(0),d,max(0);
	d=1024*512;
	for(int i=20;i>=1;i--,d/=2)
	{
		if(a/d==1)
		{
			a2[i-1]=true;
			a-=d;
		}
		else a2[i-1]=false;
	}
	d=1024*512;
	for(int i=20;i>=1;i--,d/=2)
	{
		if(b/d==1)
		{
			b2[i-1]=true;
			b-=d;
		}
		else b2[i-1]=false;
	}
	for(int i=19;i>=0;i--)
	{
		
		if(a2[i]!=b2[i]) c2[i]=true;
		else c2[i]=false;
	}
	d=1024*512;
	for(int i=19;i>=0;i--,d/=2)
	{
		if(c2[i]) c+=d;
	}
	return c;
} 
int main()
{
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n,k,b,cnt(0),abc;
	fin>>n>>k;
	int a[n],s[(n*n-n)/2],o[(n*n-n)/2];
	for(int i=0;i<n;i++)
	{
		fin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		b=a[i];
		for(int j=i+1;j<n||b==k;j++)
		{
			b=fun2(b,a[j]);
			abc=j;
		}
		if(b==k)
		{
			s[cnt]=i;
			o[cnt]=abc;
			cnt++;
		}
	}
	bool c[cnt],tc(0);
	int js(0),sum2[cnt*cnt],js2;
	for(int i=0;i<cnt*cnt;i++)
	{
		tc=false;
		for(int j=0;true;j++)
		{
			if(c[j]==true) c[j]==false;
			else
			{
				c[j]=true;
				break;
			}
		}
		for(int m=0;m<cnt;m++)
		{
			tc=false;
			if(c[m]==true)
			{
				for(int n=0;n<cnt;n++)
				{
					if(c[n]==true)
					{
						if(!(fun(s[m],o[m],s[n],o[n])))
						{
							tc=true;
							break;
						}
					}
				}
			}
			if(tc) break;
		}
		if(!(tc))
		{
			js2=0;
			for(int j=0;j<cnt;j++)
			{
				if(c[j]==true)
				{
					js2++;
				}
			}
			
			sum2[js]=js2;
			js++;
		}
		tc=false;
	}
	int max(sum2[0]);
	for(int i=1;i<js;i++)
	{
		if(sum2[i]>max)
		{
			max=sum2[i];
		}
	}
	fout<<max;
	fin.close();
	fout.close();
	return 0;
}