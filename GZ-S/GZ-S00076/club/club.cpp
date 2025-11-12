//GZ-S00076   ÎÀÒ»Ãù 
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int t;
int nx;
int n,sum1,sum2,sum3; 
struct student{
	int s1,s2,s3;
}s[100005];
int sum;
bool tmp(student a,student b)
{
	if(a.s1!=b.s1)
	{
		return a.s1>b.s1;
	}
	if(a.s2!=b.s2)
	{
		return a.s2>b.s2;
	}
	return a.s3>=b.s3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		nx=n;
		sum1=sum2=sum3=n/2;
		for(int j=0;j<n;j++)
		{
			cin>>s[j].s1>>s[j].s2>>s[j].s3;
		}	
		sort(s,s+n,tmp);
		for(int j=0;j<nx-1;j++)
		{
			if(s[j].s1>(s[j].s2+s[n-1].s1)&&s[j].s1>(s[j].s2+s[n-1].s3)&&s[j].s1>(s[j].s3+s[n-1].s1)&&s[j].s1>(s[j].s3+s[n-1].s2))
			{
				if(sum1>0)
				{
					sum+=s[j].s1;
					sum1--;
				}
				else
				{
					if(s[j].s2>(s[j].s3+s[n-1].s3))
					{
						if(sum2>0)
						{
							sum+=s[j].s2;
							sum2--;
						}
						else
						{
							sum+=s[j].s3;
							sum3--;
						}
					}
					else
					{
						if(sum3>1)
						{
							sum+=s[j].s3;
							sum+=s[n-1].s3;
							sum3-=2;
							nx--;
						}
						else
						{
							sum+=s[j].s2;
							sum2--;
						}
					}
				}
			}
			else
			{
				if(s[j].s2<=s[j].s3)
				{
					if(sum3>0)
					{
						if(s[n-1].s1<=s[n-1].s2||s[n-1].s1<=s[n-1].s3)
						{
							if(s[n-1].s2>s[n-1].s3)
							{
								if(sum2>0)
								{
									sum+=s[j].s3;
									sum+=s[n-1].s2;
									sum3--;
									sum2--;
									nx--;
								}
								else
								{									
									sum+=s[j].s3;
									sum+=s[n-1].s3;
									sum3-=2;
									nx--;																													
								}
							}
						}
					}
					else
					{
						sum+=s[j].s2;
						sum+=s[n-1].s2;
						nx--;
						sum2-=2;
					}
				}
				else
				{
					if(sum2>0)
					{
						if(s[j].s2>(s[j].s3+s[n-1].s1)&&s[j].s2>(s[j].s3+s[n-1].s2)&&s[j].s2>(s[j].s3+s[n-1].s3))
						{
							sum+=s[j].s2;
							sum2--;
						}
						if(s[n-1].s1<=s[n-1].s2&&s[n-1].s1<=s[n-1].s3)
						{
							if(s[n-1].s2>s[n-1].s3)
							{
								if(sum2>1)
								{
									sum+=s[j].s2;
									sum+=s[n-1].s2;
									sum2-=2;
									nx--;
								}
								else
								{									
									sum+=s[j].s2;
									sum+=s[n-1].s3;
									sum2--;
									sum3--;
									nx--;																													
								}
							}
						}
						else
						{
							sum+=s[j].s2;
							sum+=s[n-1].s1;
							nx--;
							sum2--;
							sum1--;
						}
					}
					else
					{
						sum+=s[j].s3;
						sum+=s[n-1].s3;
						nx--;
						sum3-=2;
					}
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
}


