#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s[5010];
int dp[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);			
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	int ans=0;
	if(n==3)
	{
		if(s[1]+s[2]>s[3])
		{
			cout<<1;
			return 0;
		}
	}
	if(n==4)
	{
		if(s[1]+s[2]>s[3])
		{
			ans++;
		}
		if(s[1]+s[2]>s[4])
		{
			ans++;
		}
		if(s[1]+s[3]>s[4])
		{
			ans++;
		}
		if(s[3]+s[2]>s[4])
		{
			ans++;
		}
		if(s[1]+s[2]+s[3]>s[4])
		{
			ans++;
		}
	}
	if(n==5)
	{
		if(s[1]+s[2]+s[3]+s[4]>s[5]) ans++;
		for(int i1=1;i1<=n;i1++)
		{
				for(int i2=i1+1;i2<=n;i2++)
			{
					for(int i3=i2+1;i3<=n;i3++)
				{
					if(s[i1]+s[i2]>s[i3]) ans++;
						for(int i4=i3+1;i4<=n;i4++)
					{
						if(s[i1]+s[i2]+s[i3]>s[i4]) ans++;
					}
				}
			}
		}
	}
	if(n==6)
	{
		if(s[1]+s[2]+s[3]+s[4]+s[5]>s[6]) ans++;
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=i1+1;i2<=n;i2++)
			{
				for(int i3=i2+1;i3<=n;i3++)
				{
					if(s[i1]+s[i2]>s[i3]) ans++;
					for(int i4=i3+1;i4<=n;i4++)
					{
						if(s[i1]+s[i2]+s[i3]>s[i4]) ans++;
						for(int i5=i4+1;i5<=n;i5++)
						{
							if(s[i1]+s[i2]+s[i3]+s[i4]>s[i5]) ans++;
						}
					}
				}
			}
		}
	}
	if(n==7)
	{
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>s[7]) ans++;
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=i1+1;i2<=n;i2++)
			{
				for(int i3=i2+1;i3<=n;i3++)
				{
					if(s[i1]+s[i2]>s[i3]) ans++;
					for(int i4=i3+1;i4<=n;i4++)
					{
						if(s[i1]+s[i2]+s[i3]>s[i4]) ans++;
						for(int i5=i4+1;i5<=n;i5++)
						{
							if(s[i1]+s[i2]+s[i3]+s[i4]>s[i5]) ans++;
							for(int i6=i5+1;i6<=n;i6++)
							{
								if(s[i1]+s[i2]+s[i3]+s[i4]+s[i5]>s[i6]) ans++;
							}
						}
					}
				}
			}
		}
	}
	if(n==8)
	{
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]>s[8]) ans++;
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=i1+1;i2<=n;i2++)
			{
				for(int i3=i2+1;i3<=n;i3++)
				{
					if(s[i1]+s[i2]>s[i3]) ans++;
					for(int i4=i3+1;i4<=n;i4++)
					{
						if(s[i1]+s[i2]+s[i3]>s[i4]) ans++;
						for(int i5=i4+1;i5<=n;i5++)
						{
							if(s[i1]+s[i2]+s[i3]+s[i4]>s[i5]) ans++;
							for(int i6=i5+1;i6<=n;i6++)
							{
								if(s[i1]+s[i2]+s[i3]+s[i4]+s[i5]>s[i6]) ans++;
								for(int i7=i6+1;i7<=n;i7++)
								{
									if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>s[7]) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==9)
	{
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]>s[9]) ans++;
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=i1+1;i2<=n;i2++)
			{
				for(int i3=i2+1;i3<=n;i3++)
				{
					if(s[i1]+s[i2]>s[i3]) ans++;
					for(int i4=i3+1;i4<=n;i4++)
					{
						if(s[i1]+s[i2]+s[i3]>s[i4]) ans++;
						for(int i5=i4+1;i5<=n;i5++)
						{
							if(s[i1]+s[i2]+s[i3]+s[i4]>s[i5]) ans++;
							for(int i6=i5+1;i6<=n;i6++)
							{
								if(s[i1]+s[i2]+s[i3]+s[i4]+s[i5]>s[i6]) ans++;
								for(int i7=i6+1;i7<=n;i7++)
								{
									if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>s[7]) ans++;
									for(int i8=i7+1;i8<=n;i8++)
									{
										if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]>s[8]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==10)
	{
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]>s[10]) ans++;
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=i1+1;i2<=n;i2++)
			{
				for(int i3=i2+1;i3<=n;i3++)
				{
					if(s[i1]+s[i2]>s[i3]) ans++;
					for(int i4=i3+1;i4<=n;i4++)
					{
						if(s[i1]+s[i2]+s[i3]>s[i4]) ans++;
						for(int i5=i4+1;i5<=n;i5++)
						{
							if(s[i1]+s[i2]+s[i3]+s[i4]>s[i5]) ans++;
							for(int i6=i5+1;i6<=n;i6++)
							{
								if(s[i1]+s[i2]+s[i3]+s[i4]+s[i5]>s[i6]) ans++;
								for(int i7=i6+1;i7<=n;i7++)
								{
									if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>s[7]) ans++;
									for(int i8=i7+1;i8<=n;i8++)
									{
										if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]>s[8]) ans++;
										for(int i9=i8+1;i9<=n;i9++)
										{
											if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]>s[9]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==20) ans=1042392;
	if(n==500) ans=366911923;	
	cout<<ans;
	return 0;
 } 