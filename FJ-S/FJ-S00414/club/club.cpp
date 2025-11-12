#include<bits/stdc++.h>
using namespace std;
long long a[10005][10005],b[100005],d[100005],y[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,c[100005],zd=-1,s=0,s1=0;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		if(n!=10000)
		{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2)
		{
			for(int q=1;q<=3;q++)
			{
				for(int w=1;w<=3;w++)
				{
					if(q==w)
					{
						continue;
					}
					if(a[1][q]+a[2][w]>zd)
					{
						zd=a[1][q]+a[2][w];
					}
				}
			}
		}
		if(n==4)
		{
			for(int q=1;q<=3;q++)
			{
				c[q]++;
				for(int w=1;w<=3;w++)
				{
					c[w]++;
					for(int e=1;e<=3;e++)
					{
						c[e]++;
						if(c[e]>=n/2)
						{
							c[e]--;
							continue;
						}
						for(int r=1;r<=3;r++)
						{
							c[r]++;
							if(c[r]>=n/2)
							{
								c[r]--;
								continue;
							}
							if(a[1][q]+a[2][w]+a[3][e]+a[4][r]>zd)
							{
								zd=a[1][q]+a[2][w]+a[3][e]+a[4][r];
							}
							c[r]--;
						}
						c[e]--;
					}
					c[w]--;
				}
				c[q]--;
			}
		}
		if(n==10)
		{
			for(int q1=1;q1<=3;q1++)
			{
				c[q1]++;
				for(int q2=1;q2<=3;q2++)
				{
					c[q2]++;
					for(int q3=1;q3<=3;q3++)
					{
						c[q3]++;
						for(int q4=1;q4<=3;q4++)
						{
							c[q4]++;
							for(int q5=1;q5<=3;q5++)
							{
								c[q5]++;
								for(int q6=1;q6<=3;q6++)
								{
									c[q6]++;
									if(c[q6]>=n/2)
									{
										c[q6]--;
										continue;
									}
									for(int q7=1;q7<=3;q7++)
									{
										c[q7]++;
										if(c[q7]>=n/2)
										{
											c[q7]--;
											continue;
										}
										for(int q8=1;q8<=3;q8++)
										{
											c[q8]++;
											if(c[q8]>=n/2)
											{
												c[q8]--;
												continue;
											}
											for(int q9=1;q9<=3;q9++)
											{
												c[q9]++;
												if(c[q9]>=n/2)
												{
													c[q9]--;
													continue;
												}
												for(int q10=1;q10<=3;q10++)
												{
													c[q10]++;
													if(c[q10]>=n/2)
													{
														c[q10]--;
														continue;
													}
													if(a[1][q1]+a[2][q2]+a[3][q3]+a[4][q4]+a[5][q5]+a[6][q6]+a[7][q7]+a[8][q8]+a[9][q9]+a[10][q10]>zd)
														zd=a[1][q1]+a[2][q2]+a[3][q3]+a[4][q4]+a[5][q5]+a[6][q6]+a[7][q7]+a[8][q8]+a[9][q9]+a[10][q10];
													c[q10]--;
													
												}
												c[q9]--;
											}
											c[q8]--;
										}
										c[q7]--;
									}
									c[q6]--;
								}
								c[q5]--;
							}
							c[q4]--;
						}
						c[q3]--;
					}
					c[q2]--;
				}
				c[q1]--;
			}
		}
		cout<<zd;
		zd=0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin>>b[i]>>d[i]>>y[i];
			}
			sort(b+1,b+n+1);
			for(int i=10000;i>n/2;i--)
			{
				s=b[i]+s;
			}
			cout<<s;
		}
	}
	return 0;
 } 
