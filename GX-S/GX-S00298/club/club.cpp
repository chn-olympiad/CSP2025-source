//club
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5;
struct stu{
	int x1,x2,x3;
	bool operator < (const stu& a)
	{
		if(x1>a.x1) return true;
		if(x2>a.x2) return true;
		if(x3>a.x3) return true;
		return false;
	}
}student[N];
int T;
int a[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		int n;
		long long ans=0;
		cin>>n;
		int m=n/2;
		for(int i=0;i<n;++i)
		cin>>student[i].x1>>student[i].x2>>student[i].x3;
		sort(student,student+n);
		for(int i=0;i<n;++i)
		{
			if(student[i].x1>student[i].x2&&student[i].x1>student[i].x3)
			{
				if(a[0]<m)
				{
					ans+=student[i].x1;
					++a[0];
				}
				else if(student[i].x2>student[i].x3)
				{
					if(a[1]<m)
					{
						ans+=student[i].x2;
						++a[1];
					}
					else{
						ans+=student[i].x3;
						++a[2];
					}
				}
			}
			if(student[i].x2>student[i].x1&&student[i].x2>student[i].x3)
			{
				if(a[1]<m)
				{
					ans+=student[i].x2;
					++a[1];
				}
				else if(student[i].x1>student[i].x3)
				{
					if(a[0]<m)
					{
						ans+=student[i].x1;
						++a[0];
					}
					else{
						ans+=student[i].x3;
						++a[2];
					}
				}
			}
			if(student[i].x3>student[i].x2&&student[i].x3>student[i].x1)
			{
				if(a[2]<m)
				{
					ans+=student[i].x3;
					++a[2];
				}
				else if(student[i].x2>student[i].x1)
				{
					if(a[1]<m)
					{
						ans+=student[i].x2;
						++a[1];
					}
					else{
						ans+=student[i].x1;
						++a[0];
					}
				}
			}
			student[i]={0,0,0};
		}
		cout<<ans<<"\n";
		a[0]=0,a[1]=0,a[2]=0;		
	}
	return 0;
}

