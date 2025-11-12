#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
int a[maxn];
int sum,maxx,ans;
bool vis[maxn];
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(maxx==1)
	{
		int ans=0;
		for(int i=3;i<=n;i++)
		{
			int sum=1;
			for(int j=i;j>=1;j--)
			{
				sum=(sum*j)%mod;
			}
			int s=1;
			for(int j=1;j<=i;j++)
			{
				s=(s*(n-j+1))%mod;
			}
			ans=(ans+s/sum)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n>=3)
	{
		for(int x1=1;x1<=n;x1++)
		{
			for(int x2=x1+1;x2<=n;x2++)
			{
				for(int x3=x2+1;x3<=n;x3++)
				{
					if((a[x1]+a[x2]+a[x3])>2*max(a[x1],max(a[x2],a[x3])))
					{
						ans++;
					}
				}
			}
		}
		if(n==3)
		{
			cout<<ans%mod;
			return 0;
		}
		if(n>=4)
		{
			for(int x1=1;x1<=n;x1++)
			{
				for(int x2=x1+1;x2<=n;x2++)
				{
					for(int x3=x2+1;x3<=n;x3++)
					{
						for(int x4=x3+1;x4<=n;x4++)
						{
							if((a[x1]+a[x2]+a[x3]+a[x4])>2*max(a[x1],max(a[x2],max(a[x3],a[x4]))))
							{
								ans++;
							}
						}
					}
				}
			}
			if(n==4)
			{
				cout<<ans%mod;
				return 0;
			}
			if(n>=5)
			{
				for(int x1=1;x1<=n;x1++)
				{
					for(int x2=x1+1;x2<=n;x2++)
					{
						for(int x3=x2+1;x3<=n;x3++)
						{
							for(int x4=x3+1;x4<=n;x4++)
							{
								for(int x5=x4+1;x5<=n;x5++)
								{
									if((a[x1]+a[x2]+a[x3]+a[x4]+a[x5])>2*max(a[x1],max(a[x2],max(a[x3],max(a[x4],a[x5])))))
									{
										ans++;
									}
								}
								
							}
						}
					}
				}
				if(n==5)
				{
					cout<<ans%mod;
					return 0;
				}
				if(n>=6)
				{
					for(int x1=1;x1<=n;x1++)
					{
						for(int x2=x1+1;x2<=n;x2++)
						{
							for(int x3=x2+1;x3<=n;x3++)
							{
								for(int x4=x3+1;x4<=n;x4++)
								{
									for(int x5=x4+1;x5<=n;x5++)
									{
										for(int x6=x5+1;x6<=n;x6++)
										{
											if((a[x1]+a[x2]+a[x3]+a[x4]+a[x5]+a[x6])>2*max(a[x1],max(a[x2],max(a[x3],max(a[x4],max(a[x5],a[x6]))))))
											{
												ans++;
												ans%=mod;
											}
										}
										
									}
									
								}
							}
						}
					}
					if(n==6)
					{
						cout<<ans;
						return 0;
					}
					if(n>=7)
					{
						for(int x1=1;x1<=n;x1++)
						{
							for(int x2=x1+1;x2<=n;x2++)
							{
								for(int x3=x2+1;x3<=n;x3++)
								{
									for(int x4=x3+1;x4<=n;x4++)
									{
										for(int x5=x4+1;x5<=n;x5++)
										{
											for(int x6=x5+1;x6<=n;x6++)
											{
												for(int x7=x6+1;x7<=n;x7++)
												{
													if((a[x1]+a[x2]+a[x3]+a[x4]+a[x5]+a[x6]+a[x7])>2*max(a[x1],max(a[x2],max(a[x3],max(a[x4],max(a[x5],max(a[x6],a[x7])))))))
													{
														ans++;
														ans%=mod;
													}
												}
												
											}									
										}									
									}
								}
							}
						}
						if(n==7)
						{
							cout<<ans%mod;
							return 0;
						}
						if(n>=8)
						{
							for(int x1=1;x1<=n;x1++)
							{
								for(int x2=x1+1;x2<=n;x2++)
								{
									for(int x3=x2+1;x3<=n;x3++)
									{
										for(int x4=x3+1;x4<=n;x4++)
										{
											for(int x5=x4+1;x5<=n;x5++)
											{
												for(int x6=x5+1;x6<=n;x6++)
												{
													for(int x7=x6+1;x7<=n;x7++)
													{
														for(int x8=x7+1;x8<=n;x8++)
														{
															if((a[x1]+a[x2]+a[x3]+a[x4]+a[x5]+a[x6]+a[x7]+a[x8])>2*max(a[x1],max(a[x2],max(a[x3],max(a[x4],max(a[x5],max(a[x6],max(a[x7],a[x8]))))))))
															{
																ans++;
																ans%=mod;
															}
														}
														
													}
													
												}									
											}									
										}
									}
								}
							}
							if(n==8)
							{
								cout<<ans;
								return 0;
							}
							if(n>=9)
							{
								for(int x1=1;x1<=n;x1++)
								{
									for(int x2=x1+1;x2<=n;x2++)
									{
										for(int x3=x2+1;x3<=n;x3++)
										{
											for(int x4=x3+1;x4<=n;x4++)
											{
												for(int x5=x4+1;x5<=n;x5++)
												{
													for(int x6=x5+1;x6<=n;x6++)
													{
														for(int x7=x6+1;x7<=n;x7++)
														{
															for(int x8=x7+1;x8<=n;x8++)
															{
																for(int x9=x8+1;x9<=n;x9++)
																{
																	if((a[x1]+a[x2]+a[x3]+a[x4]+a[x5]+a[x6]+a[x7]+a[x8]+a[x9])>2*max(a[x1],max(a[x2],max(a[x3],max(a[x4],max(a[x5],max(a[x6],max(a[x7],max(a[x8],a[x9])))))))))
																	{
																		ans++;
																		ans%=mod;
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
								if(n==9)
								{
									cout<<ans%mod;
									return 0;
								}
								if(n==10)
								{
									for(int x1=1;x1<=n;x1++)
									{
										for(int x2=x1+1;x2<=n;x2++)
										{
											for(int x3=x2+1;x3<=n;x3++)
											{
												for(int x4=x3+1;x4<=n;x4++)
												{
													for(int x5=x4+1;x5<=n;x5++)
													{
														for(int x6=x5+1;x6<=n;x6++)
														{
															for(int x7=x6+1;x7<=n;x7++)
															{
																for(int x8=x7+1;x8<=n;x8++)
																{
																	for(int x9=x8+1;x9<=n;x9++)
																	{
																		for(int x10=x9+1;x10<=n;x10++)
																		{
																			if((a[x1]+a[x2]+a[x3]+a[x4]+a[x5]+a[x6]+a[x7]+a[x8]+a[x9]+a[x10])>2*max(a[x1],max(a[x2],max(a[x3],max(a[x4],max(a[x5],max(a[x6],max(a[x7],max(a[x8],max(a[x9],a[x10]))))))))))
																			{
																				ans++;
																				ans%=mod;
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
									}
									cout<<ans%mod;
									return 0;
								}
							}
						}
					}
				}
			}
		}
		
	}
	return 0;
}

