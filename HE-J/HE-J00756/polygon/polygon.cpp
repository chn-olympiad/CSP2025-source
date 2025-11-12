#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygen.out","w",stdout);
	int n,q,sum=0,xsum=0;
	long long asd=1;
	int a[10001];
	cin >>n;
	for(int i=0;i<n;i++) 
	{
		cin >>a[i];
		xsum+=a[i];
	}
	if(xsum==n)
	{
		for(int i=3;i<=n;i++)
		{
			for(int y=i+1;y<=n;y++)
			{
				asd*=y;
			}
		}
		cout<<asd%998244353;
		return 0; 
	}
	for(int y=0;y<n;y++)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<a[i+1])
			{
				q=a[i];
				a[i]=a[i+1];
				a[i+1]=q;
			}
		}
	}
	if(n>=3)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					if(a[x]+a[y]+a[z]>a[x]*2) sum++;
				}
			}
		}
	}
	if(n>=4)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						if(a[x]+a[y]+a[z]+a[i]>a[x]*2) sum++;
					}
				}
			}
		}
	}
	if(n>=5)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							if(a[x]+a[y]+a[z]+a[i]+a[i3]>a[x]*2) sum++;
						}
					}
				}
			}
		}
	}
	if(n>=6)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<i3;i1++)
							{
								if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]>a[x]*2) sum++;
							}
						}
					}
				}
			}
		}
	}
	if(n>=7)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]>a[x]*2) sum++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n>=8)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i4]>a[x]*2) sum++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n>=9)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]>a[x]*2) sum++;
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
	if(n>=10)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i6+1;i6<n;i6++)
											{
												if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]>a[x]*2) sum++;
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
	if(n>=11)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]>a[x]*2) sum++;
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
	}
	if(n>=12)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]>a[x]*2) sum++;
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
		}
	}
	if(n>=13)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]>a[x]*2) sum++;
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
			}
		}
	}
	if(n>=14)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]>a[x]*2) sum++;
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
				}
			}
		}
	}
	if(n>=15)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																for(int i11=i10+1;i11<n;i11++)
																{
																	if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]>a[x]*2) sum++;
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
					}
				}
			}
		}
	}
	if(n>=16)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																for(int i11=i10+1;i11<n;i11++)
																{
																	for(int i12=i11+1;i12<n;i12++)
																	{
																		if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]>a[x]*2) sum++;
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
						}
					}
				}
			}
		}
	}
	if(n>=17)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																for(int i11=i10+1;i11<n;i11++)
																{
																	for(int i12=i11+1;i12<n;i12++)
																	{
																		for(int i13=i12+1;i13<n;i13++)
																		{
																			if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]>a[x]*2) sum++;
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
							}
						}
					}
				}
			}
		}
	}
	if(n>=18)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																for(int i11=i10+1;i11<n;i11++)
																{
																	for(int i12=i11+1;i12<n;i12++)
																	{
																		for(int i13=i12+1;i13<n;i13++)
																		{
																			for(int i14=i13+1;i14<n;i14++)
																			{
																				if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]>a[x]*2) sum++;
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
								}
							}
						}
					}
				}
			}
		}
	}
	if(n>=19)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																for(int i11=i10+1;i11<n;i11++)
																{
																	for(int i12=i11+1;i12<n;i12++)
																	{
																		for(int i13=i12+1;i13<n;i13++)
																		{
																			for(int i14=i13+1;i14<n;i14++)
																			{
																				for(int i15=i14+1;i15<n;i15++)
																				{
																					if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]>a[x]*2) sum++;
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
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n>=20)
	{
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				for(int z=y+1;z<n;z++)
				{
					for(int i=z+1;i<n;i++) 
					{
						for(int i3=i+1;i3<n;i3++)
						{
							for(int i1=i3+1;i1<n;i1++)
							{
								for(int i2=i1+1;i2<n;i2++)
								{
									for(int i4=i2+1;i4<n;i4++)
									{
										for(int i5=i4+1;i5<n;i5++)
										{
											for(int i6=i5+1;i6<n;i6++)
											{
												for(int i7=i6+1;i7<n;i7++)
												{
													for(int i8=i7+1;i8<n;i8++)
													{
														for(int i9=i8+1;i9<n;i9++)
														{
															for(int i10=i9+1;i10<n;i10++)
															{
																for(int i11=i10+1;i11<n;i11++)
																{
																	for(int i12=i11+1;i12<n;i12++)
																	{
																		for(int i13=i12+1;i13<n;i13++)
																		{
																			for(int i14=i13+1;i14<n;i14++)
																			{
																				for(int i15=i14+1;i15<n;i15++)
																				{
																					for(int i16=i15+1;i16<n;i16++)
																					{
																						if(a[x]+a[y]+a[z]+a[i]+a[i3]+a[i1]+a[i2]+a[i5]+a[i4]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]>a[x]*2) sum++;
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
	cout <<sum%998244353;
	return 0;
 } 
