#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a1,a2,a3;
	int a1id,a2id,a3id;
};
int fon(int w,int x,int y,int z)
{
	if(x==w)
	{
		return 1;
	}
	if(y==w)
	{
		return 2;
	}
	if(z==w)
	{
		return 3;
	}
}
bool cmp(stu a,stu b)
{
	if(a.a1==b.a1)
	{
		if(a.a2==b.a2)
		{
			return a.a3>b.a3;
		}
		else
		{
			return a.a2>b.a2;
		}
	}
	else
	{
		return a.a1>b.a1;
	}
}
int soort(int a,int b,int c,int d)
{
	int o[3]={a,b,c};
	sort(o,o+3);
	return o[3-d];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ccf m4 4母的骗我钱，娘希匹，ccf绝后又没母！ 
	//请欣赏7年级蒟蒻的屎山代码！ 
	//多多指教 
	int t;
	cin>>t;
	while(t--)
	{
		int ans=0;
		int n;
		cin>>n;
		stu a[n+2];
		stu b[n+2];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			b[i].a1=soort(a[i].a1,a[i].a2,a[i].a3,1);
			b[i].a2=soort(a[i].a1,a[i].a2,a[i].a3,2);
			b[i].a3=soort(a[i].a1,a[i].a2,a[i].a3,3);
			b[i].a1id=fon(b[i].a1,a[i].a1,a[i].a2,a[i].a3);
			b[i].a2id=fon(b[i].a2,a[i].a1,a[i].a2,a[i].a3);
			b[i].a3id=fon(b[i].a3,a[i].a1,a[i].a2,a[i].a3);
		}
		int c1=n/2,c2=n/2,c3=n/2;
		int k=0;
		sort(b+1,b+n+1,cmp);
		while(k<=n&&(c1>0||c2>0||c3>0))
		{
			k++;
			if(b[k].a1id==1&&c1>0){ans+=b[k].a1;c1--;/*cout<<b[k].a1<<' '<<b[k].a1id<<' '<<1<<' '<<c1<<endl;*/continue;}
			if(b[k].a1id==2&&c2>0){ans+=b[k].a1;c2--;/*cout<<b[k].a1<<' '<<b[k].a1id<<' '<<1<<' '<<c1<<endl;*/continue;}
			if(b[k].a1id==3&&c3>0){ans+=b[k].a1;c3--;/*cout<<b[k].a1<<' '<<b[k].a2id<<' '<<1<<' '<<c1<<endl;*/continue;}
			if(b[k].a2id==1&&c1>0){ans+=b[k].a2;c1--;/*cout<<b[k].a2<<' '<<b[k].a2id<<' '<<2<<' '<<c1<<endl;*/continue;}
			if(b[k].a2id==2&&c2>0){ans+=b[k].a2;c2--;/*cout<<b[k].a2<<' '<<b[k].a2id<<' '<<2<<' '<<c1<<endl;*/continue;}
			if(b[k].a2id==3&&c3>0){ans+=b[k].a2;c3--;/*cout<<b[k].a2<<' '<<b[k].a2id<<' '<<2<<' '<<c1<<endl;*/continue;}
			if(b[k].a3id==1&&c1>0){ans+=b[k].a3;c1--;/*cout<<b[k].a3<<' '<<b[k].a3id<<' '<<3<<' '<<c1<<endl;*/continue;}
			if(b[k].a3id==2&&c2>0){ans+=b[k].a3;c2--;/*cout<<b[k].a3<<' '<<b[k].a3id<<' '<<3<<' '<<c1<<endl;*/continue;}
			if(b[k].a3id==3&&c3>0){ans+=b[k].a3;c3--;/*cout<<b[k].a3<<' '<<b[k].a3id<<' '<<3<<' '<<c1<<endl;*/continue;}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1*/
	return 0;
}
