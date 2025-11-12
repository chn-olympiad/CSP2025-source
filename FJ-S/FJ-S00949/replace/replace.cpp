#include<bits/stdc++.h>
using namespace std;
int n,q,s,num,cf[114514],csy,cm,b1[214514],a1[214514];
bool op=0;
string a[214514],b[214541],c,d,e,f;
void belong(string s1,string s2)
{
	num=0;
	bool bb=1;
	if(s1.size()>s2.size())
	{
		return;
	}
	for(int z=0;z<s2.size();z++)
	{
		bb=1;
		for(int y=0;y<s1.size();y++)
		{
			if(z+y>s2.size())
			{
				bb=0;
				break;
			} 
			if(s1[y]!=s2[z+y])
			{
				bb=0;
				break;
			}
		}
		if(bb==1)
		{
			cf[num]=z+1;
			num++;
		}
	}
	return;
}
void belong_ab(string s1,string s2)
{
	for(int z=0;z<s2.size();z++)
	{
		if(s2[z]=='b')
		{
			cm=z;
			return;
		}
	}
	return;
}
bool cyx=1;
int main()
{
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int z=1;z<=n;z++)
	{
		cin>>a[z]>>b[z];
		for(int y=0;y<a[z].size();y++)
		{
			if(!(a[z][y]=='a'||a[z][y]=='b'))
			{
				cyx=0;
			}
		}
	}
	if(cyx==1)
	{
		for(int z=1;z<=n;z++)
		{
			for(int y=0;y<a[z].size();y++)
			{
				if(a[z][y]=='b')
				{
					a1[z]=y;
				}
				if(b[z][y]=='b')
				{
					b1[z]=y;
				}
			}
		}
		long long sum=0;
		for(int z=1;z<=q;z++)
		{
			sum=0;
			cin>>c>>d;
			for(int y=1;y<=n;y++)
			{
			    belong_ab(a[y],c);
			    csy=a1[y];
			    string szh=c;
				if(csy>cm||a[y].size()-csy>c.size()-cm)
				{
					continue;
				}
				if(cm-(csy-b1[y])>=0)
				{
					szh[cm]='a';
					szh[cm-csy+b1[y]]='b';
					if(szh==d)
					{
						sum++;
					}
				}
			}
		cout<<sum<<endl;
		}
		return 0;
	}
	for(int z=1;z<=q;z++)
	{
		op=0;
		cin>>c>>d;
			int sum=0,lxx;
			for(int y=1;y<=n;y++)
			{
				belong(a[y],c);
			for(int kkk=0;kkk<num;kkk++)
			{
				lxx=cf[kkk];
				if(lxx!=0)
				{
					lxx--;
					string szh=c;
					for(int lqy=lxx;lqy<=lxx+b[y].size()-1;lqy++)
					{
						szh[lqy]=b[y][lqy-lxx];
			    	}
					if(szh==d)
					{
						sum++;
					}
				}
			}
			
			}
			cout<<sum<<endl;
	}
	return 0;
} 
