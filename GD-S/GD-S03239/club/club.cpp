#include<bits/stdc++.h>
using namespace std;
int a[200005],n,a1,a2,a3,club1,club2,club3,sum,mi,ans1,ans2,ans3,per;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int mi=n/2;
		for(int i=1;i<=n;i++)
		{
		    cin>>a1>>a2>>a3;
		    if(a1!=a2&&a2!=a3) sum=max(a1,max(a2,a3));
		    {
		    	if(sum==a1) ans1++;
		    	if(sum==a2) ans2++;
		    	if(sum==a3) ans3++;
			}
		    if(a1==a2&&a2==a3) 
		    {   
		    	sum=a1,ans1++;
			}
		    if(a1==a2&&a2!=a3) 
		    {
			    sum=max(a1,a3);
			    if(sum==a1) ans1++;
		    	if(sum==a3) ans3++;
			}
		    if(a1==a3&&a3!=a2) 
		    {
			    sum=max(a1,a2);
		    	if(sum==a1) ans1++;
		    	if(sum==a2) ans2++;
			}
			if(a3==a1&&a1!=a2) 
		    {
			    sum=max(a1,a2);
		    	if(sum==a2) ans1++;
		    	if(sum==a3) ans2++;
			}
			if(ans1>mi) 
		    {
			   if(a1!=a2&&a2!=a3) sum=max(a2,a3);
			   else if(a1==a2&&a2==a3) sum=a2;
			   else if(a1==a2&&a2!=a3) sum=max(a2,a3);
			   else if(a1!=a2&&a2==a3) sum=max(a2,a3);
			   else if(a1=a2) sum=a2,ans2++;
			   else if(a1=a3) sum=a3,ans3++;
		    }
		    if(ans2>mi) 
		    {
			   if(a1!=a2&&a2!=a3) sum=max(a1,a3);
			   else if(a1==a2&&a2==a3) sum=a3;
			   else if(a1==a2&&a2!=a3) sum=max(a1,a3);
			   else if(a1!=a2&&a2==a3) sum=max(a1,a3);
			   else if(a1=a2) sum=a1,ans1++;
			   else if(a2=a3) sum=a3,ans3++;
		    }
		    if(ans3>mi)
		    {
			   if(a1!=a2&&a2!=a3) sum=max(a1,a2);
			   else if(a1==a2&&a2==a3) sum=a1;
			   else if(a1==a2&&a2!=a3) sum=max(a1,a2);
			   else if(a1!=a2&&a2==a3) sum=max(a1,a2);
			   else if(a1=a3) sum=a1,ans1++;
			   else if(a2=a3) sum=a2,ans2++;
		    }
		    if(a1==sum) club1+=sum;
		    if(a2==sum) club2+=sum;
		    if(a3==sum) club3+=sum; 
		    per+=max(club1,max(club2,club3));
		}
		cout<<per<<endl;
	}
	return 0;
} 
