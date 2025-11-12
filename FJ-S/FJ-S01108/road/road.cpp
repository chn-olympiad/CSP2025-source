#include<bits/stdc++.h>
using namespace std;
const int N=1e2+7;
long long getans=3141592653;
//int n,m;
//struct dd{
//	int e,w,ne;
//	int h;
//}t[N];
//void add(int a,int b,int c)
//{
//	t[idx].e=b,t[idx].w=c,t[idx].ne=t[a].h,t[a].h=idx++;
//}
//bool cnt(dd aa,dd bb)
//{
//	return aa.w>bb.w;
//}
//a[i][3]now,
//int find(int i)
//{
//	if(f[i]==i)
//	{
//		return i;
//	}
//	else return f[i]=find(f[i]);
//}
//int k()
//{
//	sort(t,t+m,cnt);
//	for(int i=0;i<m;i++)
//	{
//		;
//	}
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
int a,b,c,d,e,f,g,aaa=0;
	cin>>a>>b>>c;
	while(b--)
	{
		cin>>d>>e>>f;
		if(b==0)break;
		if(getans%(b)==f)
		{
			aaa+=f;
		}
		aaa+=e;
	}
//	while(c--)
//	{
//		cin>>g>>d>>e>>f;
//	}
	cout<<aaa;
	return 0;	
} 
