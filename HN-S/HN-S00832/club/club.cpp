#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005][3],book[4];//对于每一个数字的最大值
struct stu
{
	int x,y;
}qwq[100005];
int cmp(stu x,stu y)
{
	return x.x<y.x;
}
main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
	cin>>t;
	while(t--)
	{ 
    	cin>>n;
    	int ans=0;
    	book[0]=book[1]=book[2]=0;
    	for(int i=1;i<=n;++i)
    	{
    		cin>>a[i][0]>>a[i][1]>>a[i][2];
    		qwq[i].x=qwq[i].y=0;
    		int sum=-1,qaq=-1;
    		if(a[i][0]>=max(a[i][1],a[i][2]))
    			sum=0,qaq=a[i][0]-max(a[i][1],a[i][2]);
    		else if(a[i][1]>=a[i][2])
    			sum=1,qaq=a[i][1]-max(a[i][0],a[i][2]);
    		else
    			sum=2,qaq=a[i][2]-max(a[i][0],a[i][1]);
    		book[sum]++;
    		qwq[i].x=qaq;
    		qwq[i].y=sum;
    		ans+=a[i][sum];
//    		cout<<qwq[i].x<<" "<<qwq[i].y<<"   qwq\n";
		}
		int sum=-1;
		for(int i=0;i<3;++i)
			if(book[i]*2>n)
			{
				sum=i;
				break;
			}
//	 	cout<<ans;
		if(sum==-1)
		{
			cout<<ans<<"\n";
			continue;
		}
		sort(qwq+1,qwq+1+n,cmp);
    	for(int i=1;i<=n;++i) 
    	{
    		if(book[sum]*2<=n)
    			break;
    		if(qwq[i].y==sum)
    		{
    			ans-=qwq[i].x;
    			book[sum]--;
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

151494
146088


147325
125440
152929
150176
158541

*/ 
