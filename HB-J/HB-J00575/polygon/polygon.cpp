#include<bits/stdc++.h>
using namespace std;
int s[110],tongji[500010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0,f=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	if(n==2)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	if(n==3)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	for(int c=-1;c<=1;c++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(c==1)
		t+=s[3],tongji[f]+=100;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		if(c==1&&s[3]>maxn)
		maxn=s[3];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	if(n==4)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	for(int c=-1;c<=1;c++)
	for(int d=-1;d<=1;d++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(c==1)
		t+=s[3],tongji[f]+=100;
		if(d==1)
		t+=s[4],tongji[f]+=1000;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		if(c==1&&s[3]>maxn)
		maxn=s[3];
		if(d==1&&s[4]>maxn)
		maxn=s[4];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	if(n==5)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	for(int c=-1;c<=1;c++)
	for(int d=-1;d<=1;d++)
	for(int e=-1;e<=1;e++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(c==1)
		t+=s[3],tongji[f]+=100;
		if(d==1)
		t+=s[4],tongji[f]+=1000;
		if(e==1)
		t+=s[5],tongji[f]+=10000;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		if(c==1&&s[3]>maxn)
		maxn=s[3];
		if(d==1&&s[4]>maxn)
		maxn=s[4];
		if(e==1&&s[5]>maxn)
		maxn=s[5];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	if(n==6)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	for(int c=-1;c<=1;c++)
	for(int d=-1;d<=1;d++)
	for(int e=-1;e<=1;e++)
	for(int g=-1;g<=1;g++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(c==1)
		t+=s[3],tongji[f]+=100;
		if(d==1)
		t+=s[4],tongji[f]+=1000;
		if(e==1)
		t+=s[5],tongji[f]+=10000;
		if(g==1)
		t+=s[6],tongji[f]+=100000;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		if(c==1&&s[3]>maxn)
		maxn=s[3];
		if(d==1&&s[4]>maxn)
		maxn=s[4];
		if(e==1&&s[5]>maxn)
		maxn=s[5];
		if(g==1&&s[6]>maxn)
		maxn=s[6];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	if(n==7)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	for(int c=-1;c<=1;c++)
	for(int d=-1;d<=1;d++)
	for(int e=-1;e<=1;e++)
	for(int g=-1;g<=1;g++)
	for(int h=-1;h<=1;h++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(c==1)
		t+=s[3],tongji[f]+=100;
		if(d==1)
		t+=s[4],tongji[f]+=1000;
		if(e==1)
		t+=s[5],tongji[f]+=10000;
		if(g==1)
		t+=s[6],tongji[f]+=100000;
		if(h==1)
		t+=s[7],tongji[f]+=1000000;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		if(c==1&&s[3]>maxn)
		maxn=s[3];
		if(d==1&&s[4]>maxn)
		maxn=s[4];
		if(e==1&&s[5]>maxn)
		maxn=s[5];
		if(g==1&&s[6]>maxn)
		maxn=s[6];
		if(h==1&&s[7]>maxn)
		maxn=s[7];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	if(n==8)
	for(int a=-1;a<=1;a++)
	for(int b=-1;b<=1;b++)
	for(int c=-1;c<=1;c++)
	for(int d=-1;d<=1;d++)
	for(int e=-1;e<=1;e++)
	for(int g=-1;g<=1;g++)
	for(int h=-1;h<=1;h++)
	{
		f++;
		int t=0,maxn=0;
		if(a==1)
		t+=s[1],tongji[f]+=1;
		if(b==1)
		t+=s[2],tongji[f]+=10;
		if(c==1)
		t+=s[3],tongji[f]+=100;
		if(d==1)
		t+=s[4],tongji[f]+=1000;
		if(e==1)
		t+=s[5],tongji[f]+=10000;
		if(g==1)
		t+=s[6],tongji[f]+=100000;
		if(h==1)
		t+=s[7],tongji[f]+=1000000;
		if(a==1&&s[1]>maxn)
		maxn=s[1];
		if(b==1&&s[2]>maxn)
		maxn=s[2];
		if(c==1&&s[3]>maxn)
		maxn=s[3];
		if(d==1&&s[4]>maxn)
		maxn=s[4];
		if(e==1&&s[5]>maxn)
		maxn=s[5];
		if(g==1&&s[6]>maxn)
		maxn=s[6];
		if(h==1&&s[7]>maxn)
		maxn=s[7];
		int p=1;
		if(t>maxn*2)
		{
			for(int i=1;i<f;i++)
				if(tongji[f]==tongji[i])
					p=0;
			if(p==1)
				num++;
		}
	}
	cout<<num;
	return 0;
}
