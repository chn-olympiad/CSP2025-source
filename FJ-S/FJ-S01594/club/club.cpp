#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef double llf;
//-----------------------------
struct stu
{
	int x,y,z;
	int id;
	int _id;
}a[100010],c[100010],d[100010],e[100010];
bool cmp1(stu aw,stu ew)
{
	return min(aw.y,aw.z)>min(ew.y,ew.z);
}
bool cmp2(stu aw,stu ew)
{
	return min(aw.x,aw.z)>min(ew.x,ew.z);
}
bool cmp3(stu aw,stu ew)
{
	return min(aw.y,aw.x)>min(ew.y,ew.x);
}
int Q,n;
int xl,yl,zl;
int cl,dl,el;
void gt(int _k)
{
	stu k=a[_k];
	if(k.x>k.y)
	{
		if(k.x>k.z)
		{
			++xl;
			a[_k].id=1;
			c[++cl]=a[_k];
			c[cl].y=a[_k].x-a[_k].y;
			c[cl].z=a[_k].x-a[_k].z;
		}
		else
		{
			++zl;
			a[_k].id=3;
			e[++el]=a[_k];
			e[el].y=a[_k].z-a[_k].y;
			e[el].x=a[_k].z-a[_k].x;
		}
	}
	else
	{
		if(k.y>k.z)
		{
			++yl;
			a[_k].id=2;
			d[++dl]=a[_k];
			d[dl].x=a[_k].y-a[_k].x;
			d[dl].z=a[_k].y-a[_k].z;
		}
		else
		{
			++zl;
			a[_k].id=3;
			e[++el]=a[_k];
			e[el].y=a[_k].z-a[_k].y;
			e[el].x=a[_k].z-a[_k].x;
		}
	}
	return;
}

lld sum=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Q;
	while(Q--)
	{
		sum=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		xl=yl=zl=0;
		cl=dl=el=0;
		
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i]._id=i;
			gt(i);
		}
		
		
		
		//X
		if(xl>n/2)
		{
			
			sort(c+1,c+cl+1,cmp1);
			for(int i=n/2+1;i<=cl;++i)
			{
				if(a[c[i]._id].y>a[c[i]._id].z)
					a[c[i]._id].id=2;
				else
					a[c[i]._id].id=3;
			}
		}
		//Y
		if(yl>n/2)
		{
			
			sort(d+1,d+dl+1,cmp2);
			for(int i=n/2+1;i<=dl;++i)
			{
				if(a[d[i]._id].x>a[d[i]._id].z)
					a[d[i]._id].id=1;
				else
					a[d[i]._id].id=3;
			}
		}
		//Z
		if(zl>n/2)
		{
			sort(e+1,e+el+1,cmp3);
			for(int i=n/2+1;i<=el;++i)
			{
				if(a[e[i]._id].y>a[e[i]._id].x)
					a[e[i]._id].id=2;
				else
					a[e[i]._id].id=1;
			}
		}
		
		for(int i=1;i<=n;++i)
		{
			if(a[i].id==1)sum+=a[i].x;
			if(a[i].id==2)sum+=a[i].y;
			if(a[i].id==3)sum+=a[i].z;
		}
		
		cout<<sum<<endl;
	}
	//LQH保佑我~zr保佑我~ 
	//保佑我这题100分 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
