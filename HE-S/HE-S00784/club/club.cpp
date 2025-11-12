#include<bits/stdc++.h>
using namespace std;
struct xy{
	int x;
	int y;
	int z;
};
xy a[100001];
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	 cin>>t;
	 for(int j=0;j<t;j++)
	 {
	    int n,sum=0,ans=0,q,w,e;
	    cin>>n;
	 	for(int i=0;i<n;i++)
	 	{
	 		cin>>a[i].x>>a[i].y>>a[i].z;
	 		ans=max(a[i].x,a[i].y);
	 		if(ans<a[i].z)
	 		{
	 			ans=a[i].z;
			 }
	 		if(ans==a[i].x)
	 		{
	 			q++;
	 			if(q>n/2)
	 			{
	 			    ans=a[i].x;
	 			    sum=sum-a[0].x;
				}
			}else{
				if(ans==a[i].y)
				{
					w++;
					if(w>n/2)
					{
						ans=a[i].y;
						sum=sum-a[0].y;
					}
				}else{
					if(ans==a[i].z)
					{
						e++;
						if(e>n/2)
						{
							ans=a[i].z;
							sum=sum-a[0].z;
						}
					}

				}
			}
			sum=sum+ans;
		}
		cout<<sum<<endl;
	 }
	 return 0;
}
