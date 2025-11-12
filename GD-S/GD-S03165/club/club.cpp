#include<bits/stdc++.h>
using namespace std;
struct myd{
	int one,two,three;
	int max_()
	{
		int a=max(one,two),b=max(two,three);
		return max(a,b);
	}
	int& operator[](int d)
	{
		if(d==0)
		return one;
		else if(d==1)
		return two;
		else
		return three;
	}
	bool operator<(myd m)
	{
		return max_()>m.max_();
	}
}a[100005];
//int a[100005][3];//满意度 
int po[3];//1,2,3部门人数 
struct ar{//数组元素 
	int v;
	int d;
	bool operator<(ar a)
	{
		return v<a.v;
	}
	void operator=(int a)
	{
		v=a;
	}
};
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;++j)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		}
		sort(a,a+n);
		int hf=n/2,ans=0;
		for(int j=0;j<n;++j)
		{
			ar p[3];
			p[0]=a[j][0];p[0].d=0;
			p[1]=a[j][1];p[1].d=1;
			p[2]=a[j][2];p[2].d=2;
			sort(p,p+3);
			if(po[p[2].d]<hf)
			{
				++po[p[2].d];
				ans+=p[2].v;
				//cout<<j+1<<":"<<p[2].d+1<<endl;
			}
			else if(po[p[1].d]<hf)
			{
				++po[p[1].d];
				ans+=p[1].v;
				//cout<<j+1<<":"<<p[1].d+1<<endl;
			}
			else
			{
				++po[p[0].d];
				ans+=p[0].v;
				//cout<<j+1<<":"<<p[0].d+1<<endl;
			}
		}
	//	cout<<"ans:"<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
