#include<iostream>
using namespace std;
int n,t,big;
int b1[10005],b2[10005],b3[10005],zx[10005],jz[10005],b[10005];
int main()
{
	cin>>t;
	for (int j=1;j<=t;j++)
	{
		int sum=0;
		int c1=0,c2=0,c3=0,maxx=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>b1[i]>>b2[i]>>b3[i];
		}
		for (int i=1;i<=n;i++)
		{
			if (b1[i]>b2[i] && b1[i]>b3[i])
			{
				zx[i]=1;
				c1++;
			}
			if (b2[i]>b1[i] && b2[i]>b3[i])
			{
				zx[i]=2;
				c2++;
			}
			if (b3[i]>b2[i] && b3[i]>b1[i])
			{
				zx[i]=3;
				c3++;
			}
			if (b1[i]==b2[i] && b1[i]>b3[i])
			{
				zx[i]=12;
			}
			if (b1[i]==b3[i] && b1[i]>b2[i])
			{
				zx[i]=13;
			}
			if (b3[i]==b2[i] && b3[i]>b1[i])
			{
				zx[i]=23;
			}
			if (b1[i]==b2[i] && b1[i]==b3[i])
			{
				zx[i]=123;
			}
		}
		if (c1>n/2)
		{
			while(c1>n/2)
			{
				int ans=1000;
				int mark=0;
				for (int i=1;i<=n;i++)
				{
					if (zx[i]==1)
					{
						if (c2>=n/2)
						{
							jz[i]=b3[i]-b1[i];
							b[i]=3;
						}
						else if (c3>=n/2)
						{
							jz[i]=b2[i]-b1[i];
							b[i]=2;
						}
						else
						{
							if (b2[i]==b3[i])
							{
								if (c2>c3)
								{
									jz[i]=b3[i]-b1[i];
									b[i]=3;
								}
								else if(c2<c3)
								{
									jz[i]=b2[i]-b1[i];
									b[i]=2;
								}
								else
								{
									jz[i]=b2[i]-b1[i];
									b[i]=2;
								}
							}
							else if(b2[i]<b3[i])
							{
								jz[i]=b3[i]-b1[i];
								b[i]=3;
							}
							else
							{
								jz[i]=b2[i]-b1[i];
								b[i]=2;
							}
						}
						if (jz[i]<ans)
						{
							ans=jz[i];
							mark=i;
						}
					}
				}
				c1--;
				if (b[mark]==2)
				{
					c2++;
					zx[mark]=2;
				}
				else
				{
					zx[mark]=3;
					c3++;
				}
			}
		}
		if (c2>n/2)
		{
			while(c2>n/2)
			{
				int ans=1000;
				int mark=0;
				for (int i=1;i<=n;i++)
				{
					if (zx[i]==2)
					{
						if (c1>=n/2)
						{
							jz[i]=b3[i]-b2[i];
							b[i]=3;
						}
						else if (c3>=n/2)
						{
							jz[i]=b1[i]-b2[i];
							b[i]=1;
						}
						else
						{
							if (b1[i]==b3[i])
							{
								if (c1>c3)
								{
									jz[i]=b3[i]-b2[i];
									b[i]=3;
								}
								else if(c1<c3)
								{
									jz[i]=b1[i]-b2[i];
									b[i]=1;
								}
								else
								{
									jz[i]=b1[i]-b2[i];
									b[i]=1;
								}
							}
							else if(b1[i]<b3[i])
							{
								jz[i]=b3[i]-b2[i];
								b[i]=3;
							}
							else
							{
								jz[i]=b1[i]-b2[i];
								b[i]=1;
							}
						}
						if (jz[i]<ans)
						{
							ans=jz[i];
							mark=i;
						}
					}
				}
				c1--;
				if (b[mark]==1)
				{
					c1++;
					zx[mark]=1;
				}
				else
				{
					zx[mark]=3;
					c3++;
				}
			}
		}
		if (c3>n/2)
		{
			while(c3>n/2)
			{
				int ans=1000;
				int mark=0;
				for (int i=1;i<=n;i++)
				{
					if (zx[i]==3)
					{
						if (c2>=n/2)
						{
							jz[i]=b1[i]-b3[i];
							b[i]=1;
						}
						else if (c1>=n/2)
						{
							jz[i]=b2[i]-b3[i];
							b[i]=2;
						}
						else
						{
							if (b2[i]==b1[i])
							{
								if (c2>c1)
								{
									jz[i]=b1[i]-b3[i];
									b[i]=1;
								}
								else if(c2<c1)
								{
									jz[i]=b2[i]-b3[i];
									b[i]=2;
								}
								else
								{
									jz[i]=b2[i]-b3[i];
									b[i]=2;
								}
							}
							else if(b2[i]<b1[i])
							{
								jz[i]=b1[i]-b3[i];
								b[i]=1;
							}
							else
							{
								jz[i]=b2[i]-b3[i];
								b[i]=2;
							}
						}
						if (jz[i]<ans)
						{
							ans=jz[i];
							mark=i;
						}
					}
				}
				c1--;
				if (b[mark]==2)
				{
					c2++;
					zx[mark]=2;
				}
				else
				{
					zx[mark]=1;
					c1++;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (zx[i]==1)
			{
				sum+=b1[i];
			}
			else if (zx[i]==2)
			{
				sum+=b2[i];
			}
			else if (zx[i]==3)
			{
				sum+=b3[i];
			}
			else if (zx[i]==12 || zx[i]==13 || zx[i]==123)
			{
				sum+=b1[i];
			}
			else
			{
				sum+=b2[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
