#include<bits/stdc++.h>
using namespace std;
int b[100],p=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>20)
	{
		int o=0;
		for(int i=3;i<=n/2;i++)
		{
			int a=1;
			for(int j=n-i+1;j>n-i-i+1;j--)
			{
				a*=j;
				a=a%998244353;
			}
			o+=a;
			o=o%998244353;
			o*=2;
			o=o%998244353;
		}
		cout<<o<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
			cin>>b[i];
		sort(b+1,b+n+1);
		for(int op=3;op<=n;op++)
		{
			for(int i=op;i<=n;i++)
			{
				if(op==3)
				{
					for(int j=2;j<i;j++)
					{
						for(int k=1;k<j;k++)
						{
							if(b[k]+b[j]>b[i])
								p++;
						}
					}
				}if(op==4)
				{
					for(int j=3;j<i;j++)
					{
						for(int k=2;k<j;k++)
						{
							for(int kl=1;kl<k;kl++)
							{
								if(b[k]+b[j]+b[kl]>b[i])
									p++;
							}
						}
					}
				}if(op==10)
				{
					for(int j=9;j<i;j++)
					{
						for(int k=8;k<j;k++)
						{
							for(int kl=7;kl<k;kl++)
							{
								for(int kk=6;kk<kl;kk++)
								{
									for(int kj=5;kj<kk;kj++)
									{
										for(int kh=4;kh<kj;kh++)
										{
											for(int kg=3;kg<kh;kg++)
											{
												for(int kf=2;kf<kg;kf++)
												{
													for(int kd=1;kd<kf;kd++)
													{
														if(b[k]+b[j]+b[kl]+b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]>b[i])
															p++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}if(op==9)
				{
						for(int k=8;k<i;k++)
						{
							for(int kl=7;kl<k;kl++)
							{
								for(int kk=6;kk<kl;kk++)
								{
									for(int kj=5;kj<kk;kj++)
									{
										for(int kh=4;kh<kj;kh++)
										{
											for(int kg=3;kg<kh;kg++)
											{
												for(int kf=2;kf<kg;kf++)
												{
													for(int kd=1;kd<kf;kd++)
													{
														if(b[k]+b[kl]+b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]>b[i])
															p++;
													}
												}
											}
										}
									}
								}
							}
						}
				}if(op==8)
				{
							for(int kl=7;kl<i;kl++)
							{
								for(int kk=6;kk<kl;kk++)
								{
									for(int kj=5;kj<kk;kj++)
									{
										for(int kh=4;kh<kj;kh++)
										{
											for(int kg=3;kg<kh;kg++)
											{
												for(int kf=2;kf<kg;kf++)
												{
													for(int kd=1;kd<kf;kd++)
													{
														if(b[kl]+b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]>b[i])
															p++;
													}
												}
											}
										}
									}
								}
							}
				}if(op==7)
				{
								for(int kk=6;kk<i;kk++)
								{
									for(int kj=5;kj<kk;kj++)
									{
										for(int kh=4;kh<kj;kh++)
										{
											for(int kg=3;kg<kh;kg++)
											{
												for(int kf=2;kf<kg;kf++)
												{
													for(int kd=1;kd<kf;kd++)
													{
														if(b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]>b[i])
															p++;
													}
												}
											}
										}
									}
								}
				}if(op==6)
				{
									for(int kj=5;kj<i;kj++)
									{
										for(int kh=4;kh<kj;kh++)
										{
											for(int kg=3;kg<kh;kg++)
											{
												for(int kf=2;kf<kg;kf++)
												{
													for(int kd=1;kd<kf;kd++)
													{
														if(b[kj]+b[kh]+b[kg]+b[kf]+b[kd]>b[i])
															p++;
													}
												}
											}
										}
									}
								
				}if(op==5)
				{
										for(int kh=4;kh<i;kh++)
										{
											for(int kg=3;kg<kh;kg++)
											{
												for(int kf=2;kf<kg;kf++)
												{
													for(int kd=1;kd<kf;kd++)
													{
														if(b[kh]+b[kg]+b[kf]+b[kd]>b[i])
															p++;
													}
												}
											}
										}
									
				}if(op==20)
				{
					for(int j=19;j<i;j++)
					{
						for(int k=18;k<j;k++)
						{
							for(int kl=17;kl<k;kl++)
							{
								for(int kk=16;kk<kl;kk++)
								{
									for(int kj=15;kj<kk;kj++)
									{
										for(int kh=14;kh<kj;kh++)
										{
											for(int kg=13;kg<kh;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[k]+b[j]+b[kl]+b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
				}if(op==19)
				{
						for(int k=18;k<i;k++)
						{
							for(int kl=17;kl<k;kl++)
							{
								for(int kk=16;kk<kl;kk++)
								{
									for(int kj=15;kj<kk;kj++)
									{
										for(int kh=14;kh<kj;kh++)
										{
											for(int kg=13;kg<kh;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[k]+b[kl]+b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
					
				}if(op==18)
				{
					
							for(int kl=17;kl<i;kl++)
							{
								for(int kk=16;kk<kl;kk++)
								{
									for(int kj=15;kj<kk;kj++)
									{
										for(int kh=14;kh<kj;kh++)
										{
											for(int kg=13;kg<kh;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kl]+b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
						
				}if(op==17)
				{
								for(int kk=16;kk<i;kk++)
								{
									for(int kj=15;kj<kk;kj++)
									{
										for(int kh=14;kh<kj;kh++)
										{
											for(int kg=13;kg<kh;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kk]+b[kj]+b[kh]+b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
							
				}if(op==16)
				{
									for(int kj=15;kj<i;kj++)
									{
										for(int kh=14;kh<kj;kh++)
										{
											for(int kg=13;kg<kh;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kj]+b[kh]+b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
								
				}if(op==15)
				{
										for(int kh=14;kh<i;kh++)
										{
											for(int kg=13;kg<kh;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kh]+b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
									
				}if(op==14)
				{
											for(int kg=13;kg<i;kg++)
											{
												for(int kf=12;kf<kg;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kg]+b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
										
				}if(op==13)
				{
												for(int kf=12;kf<i;kf++)
												{
													for(int kd=11;kd<kf;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kf]+b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
											
				}if(op==12)
				{
													for(int kd=11;kd<i;kd++)
													{
														for(int kp=10;kp<kd;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kd]+b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
												
				}if(op==11)
				{
														for(int kp=10;kp<i;kp++)
														{
															for(int ko=9;ko<kp;ko++)
															{
																for(int ki=8;ki<ko;ki++)
																{
																	for(int ku=7;ku<ki;ku++)
																	{
																		for(int ky=6;ky<ku;ky++)
																		{
																			for(int kt=5;kt<ky;kt++)
																			{
																				for(int kr=4;kr<kt;kr++)
																				{
																					for(int ke=3;ke<kr;ke++)
																					{
																						for(int kw=2;kw<ke;kw++)
																						{
																							for(int kq=1;kq<kw;kq++)
																							{
																								if(b[kp]+b[ko]+b[ki]+b[ku]+b[ky]+b[kt]+b[kr]+b[ke]+b[kw]+b[kq]>b[i])
																									p++;
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
		cout<<p;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
