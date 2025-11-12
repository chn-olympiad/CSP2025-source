#include<bits/stdc++.h> 
using namespace std;

bool flag;
struct sat{
	int a,b,c;
}student[100010];
int a2[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int n=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>student[i].a>>student[i].b>>student[i].c;
			if(student[i].b!=0 || student[i].c!=0)
			flag=1;
			if(!flag)
			a2[i]=student[i].a;
		}
		if(n==2)
		{
			int maxn1=max(max(student[1].a,student[1].b),student[1].c);
			int maxn2=max(max(student[2].a,student[2].b),student[2].c);
			int minn1=min(min(student[1].a,student[1].b),student[1].c);
			int minn2=min(min(student[2].a,student[2].b),student[2].c);
			if(student[1].a<maxn1 &&student[1].a>minn1)
			{
				if(student[2].a<maxn2 &&student[2].a>minn2)
				cout<<max(student[1].a+maxn2,student[2].a+maxn1);
				if(student[2].b<maxn2 &&student[2].b>minn2)
				cout<<max(student[1].a+maxn2,student[2].b+maxn1);
				if(student[2].c<maxn2 &&student[2].c>minn2)
				cout<<max(student[1].a+maxn2,student[2].c+maxn1);
			}
			if(student[1].b<maxn1 &&student[1].b>minn1)
			{
				if(student[2].a<maxn2 &&student[2].a>minn2)
				cout<<max(student[1].b+maxn2,student[2].a+maxn1);
				if(student[2].b<maxn2 &&student[2].b>minn2)
				cout<<max(student[1].b+maxn2,student[2].b+maxn1);
				if(student[2].c<maxn2 &&student[2].c>minn2)
				cout<<max(student[1].b+maxn2,student[2].c+maxn1);
			}
			if(student[1].c<maxn1 &&student[1].c>minn1)
			{
				if(student[2].a<maxn2 &&student[2].a>minn2)
				cout<<max(student[1].c+maxn2,student[2].a+maxn1);
				if(student[2].b<maxn2 &&student[2].b>minn2)
				cout<<max(student[1].c+maxn2,student[2].b+maxn1);
				if(student[2].c<maxn2 &&student[2].c>minn2)
				cout<<max(student[1].c+maxn2,student[2].c+maxn1);
			}
		}
		if(!flag)
		{
			sort(a2+1,a2+1+n);
			for(int i=n;i>n/2;i--)
			{
				ans+=a2[i];
			 } 
			 cout<<ans<<endl;
		}
	 }
	 return 0; 
}
