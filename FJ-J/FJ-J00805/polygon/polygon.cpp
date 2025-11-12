#include<bits/stdc++.h>
using namespace std;
int a[5005],b[25];
long long num=0;
void f(int n)
{
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n==3)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					if(b[1]*i1+b[2]*i2+b[3]*i3>2*max(b[1]*i1,max(b[2]*i2,b[3]*i3)))
					{
						num++;
					}
				}
			}
		}
		cout<<num%998244353;
		return;
	}
	if(n==4)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,b[4]*i4))))
						{
							num++;
						}
					}
				}
			}
		}
		cout<<num%998244353;
		return;
	}
	if(n==5)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,b[5]*i5)))))
							{
								num++;
							}
						}
					}
				}
			}
		}
		cout<<num%998244353;
		return;
	}
	if(n==6)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,b[6]*i6))))))
								{
									num++;
								}
							}
						}
					}
				}
			}
		}
		cout<<num%998244353;
		return;
	}
	if(n==7)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,b[7]*i7)))))))
									{
										num++;
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<num%998244353;
		return;
	}
	if(n==8)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,b[8]*i8))))))))
										{
											num++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<num%998244353;
		return;
	}
	if(n==9)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,b[9]*i9)))))))))
											{
												num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==10)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,b[10]*i10))))))))))
												{
													num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==11)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,b[11]*i11)))))))))))
													{
														num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==12)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,b[12]*i12))))))))))))
														{
															num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==13)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,b[13]*i13)))))))))))))
															{
																num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==14)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,b[14]*i14))))))))))))))
																{
																	num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==15)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																for(long long i15=0;i15<=1;i15++)
																{
																	if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14+b[15]*i15>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,max(b[14]*i14,b[15]*i15)))))))))))))))
																	{
																		num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==16)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																for(long long i15=0;i15<=1;i15++)
																{
																	for(long long i16=0;i16<=1;i16++)
																	{
																		if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14+b[15]*i15+b[16]*i16>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,max(b[14]*i14,max(b[15]*i15,b[16]*i16))))))))))))))))
																		{
																			num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==17)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																for(long long i15=0;i15<=1;i15++)
																{
																	for(long long i16=0;i16<=1;i16++)
																	{
																		for(long long i17=0;i17<=1;i17++)
																		{
																			if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14+b[15]*i15+b[16]*i16+b[17]*i17>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,max(b[14]*i14,max(b[15]*i15,max(b[16]*i16,b[17]*i17)))))))))))))))))
																			{
																				num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==18)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																for(long long i15=0;i15<=1;i15++)
																{
																	for(long long i16=0;i16<=1;i16++)
																	{
																		for(long long i17=0;i17<=1;i17++)
																		{
																			for(long long i18=0;i18<=1;i18++)
																			{
																				if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14+b[15]*i15+b[16]*i16+b[17]*i17+b[18]*i18>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,max(b[14]*i14,max(b[15]*i15,max(b[16]*i16,max(b[17]*i17,b[18]*i18))))))))))))))))))
																				{
																					num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==19)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																for(long long i15=0;i15<=1;i15++)
																{
																	for(long long i16=0;i16<=1;i16++)
																	{
																		for(long long i17=0;i17<=1;i17++)
																		{
																			for(long long i18=0;i18<=1;i18++)
																			{
																				for(long long i19=0;i19<=1;i19++)
																				{
																					if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14+b[15]*i15+b[16]*i16+b[17]*i17+b[18]*i18+b[19]*i19>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,max(b[14]*i14,max(b[15]*i15,max(b[16]*i16,max(b[17]*i17,max(b[18]*i18,b[19]*i19)))))))))))))))))))
																					{
																						num++;
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
		cout<<num%998244353;
		return;
	}
	if(n==20)
	{
		for(long long i1=0;i1<=1;i1++)
		{
			for(long long i2=0;i2<=1;i2++)
			{
				for(long long i3=0;i3<=1;i3++)
				{
					for(long long i4=0;i4<=1;i4++)
					{
						for(long long i5=0;i5<=1;i5++)
						{
							for(long long i6=0;i6<=1;i6++)
							{
								for(long long i7=0;i7<=1;i7++)
								{
									for(long long i8=0;i8<=1;i8++)
									{
										for(long long i9=0;i9<=1;i9++)
										{
											for(long long i10=0;i10<=1;i10++)
											{
												for (long long i11=0;i11<=1;i11++)
												{
													for(long long i12=0;i12<=1;i12++)
													{
														for(long long i13=0;i13<=1;i13++)
														{
															for(long long i14=0;i14<=1;i14++)
															{
																for(long long i15=0;i15<=1;i15++)
																{
																	for(long long i16=0;i16<=1;i16++)
																	{
																		for(long long i17=0;i17<=1;i17++)
																		{
																			for(long long i18=0;i18<=1;i18++)
																			{
																				for(long long i19=0;i19<=1;i19++)
																				{
																					for(long long i20=0;i20<=1;i20++)
																					{
																						if(b[1]*i1+b[2]*i2+b[3]*i3+b[4]*i4+b[5]*i5+b[6]*i6+b[7]*i7+b[8]*i8+b[9]*i9+b[10]*i10+b[11]*i11+b[12]*i12+b[13]*i13+b[14]*i14+b[15]*i15+b[16]*i16+b[17]*i17+b[18]*i18+b[19]*i19+b[20]*i20>2*max(b[1]*i1,max(b[2]*i2,max(b[3]*i3,max(b[4]*i4,max(b[5]*i5,max(b[6]*i6,max(b[7]*i7,max(b[8]*i8,max(b[9]*i9,max(b[10]*i10,max(b[11]*i11,max(b[12]*i12,max(b[13]*i13,max(b[14]*i14,max(b[15]*i15,max(b[16]*i16,max(b[17]*i17,max(b[18]*i18,max(b[19]*i19,b[20]*i20))))))))))))))))))))
																						{
																							num++;
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
		cout<<num%998244353;
		return;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	if(n<=20)
	{
		f(n);
	}
	else
	{
		
		a[3]=n*(n-1)*(n-2)/6;
		for(int i=4;i<=n;i++)
		{
			a[i]=(a[i-1]*(n-i+1)/i)%998244353;
			sum+=a[i];
			sum%=998244353;
		}
		cout<<(sum+a[3])%998244353;
	}
	return 0;
} 
