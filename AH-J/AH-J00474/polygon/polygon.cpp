#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,flag=1,sum=0,mx=0; scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=0;
		sum+=a[i],mx=max(mx,a[i]);
	}
	if(n<3)
	{
		printf("0\n");
		return 0;
	}
	if(flag)
	{
		printf("%d\n",n-2);
		return 0;
	}
	if(n==3)
	{
		if(sum>(mx*2)) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(n<=20)
	{
		int ans=0;
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
				{
					int mx=max(max(a[i1],a[i2]),a[i3]),sum=a[i1]+a[i2]+a[i3];
					if(sum>(mx*2)) ans++;
				}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
					{
						int mx=max(max(max(a[i1],a[i2]),a[i3]),a[i4]),sum=a[i1]+a[i2]+a[i3]+a[i4];
						if(sum>(mx*2)) ans++;
					}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
						{
							int mx=max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5];
							if(sum>(mx*2)) ans++;
						}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
							{
								int mx=max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6];
								if(sum>(mx*2)) ans++;
							}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
								{
									int mx=max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7];
									if(sum>(mx*2)) ans++;
								}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
									{
										int mx=max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8];
										if(sum>(mx*2)) ans++;
									}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
										{
											int mx=max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9];
											if(sum>(mx*2)) ans++;
										}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
											{
												int mx=max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10];
												if(sum>(mx*2)) ans++;
											}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
												{
													int mx=max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11];
													if(sum>(mx*2)) ans++;
												}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
													{
														int mx=max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12];
														if(sum>(mx*2)) ans++;
													}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
														{
															int mx=max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13];
															if(sum>(mx*2)) ans++;
														}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
															{
																int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14];
																if(sum>(mx*2)) ans++;
															}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
																for(int i15=i14+1;i15<=n;i15++)
																{
																	int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),a[i15]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15];
																	if(sum>(mx*2)) ans++;
																}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
																for(int i15=i14+1;i15<=n;i15++)
																	for(int i16=i15+1;i16<=n;i16++)
																	{
																		int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),a[i15]),a[i16]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16];
																		if(sum>(mx*2)) ans++;
																	}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
																for(int i15=i14+1;i15<=n;i15++)
																	for(int i16=i15+1;i16<=n;i16++)
																		for(int i17=i16+1;i17<=n;i17++)
																		{
																			int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),a[i15]),a[i16]),a[i17]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17];
																			if(sum>(mx*2)) ans++;
																		}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
																for(int i15=i14+1;i15<=n;i15++)
																	for(int i16=i15+1;i16<=n;i16++)
																		for(int i17=i16+1;i17<=n;i17++)
																			for(int i18=i17+1;i18<=n;i18++)
																			{
																				int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),a[i15]),a[i16]),a[i17]),a[i18]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17]+a[i18];
																				if(sum>(mx*2)) ans++;
																			}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
																for(int i15=i14+1;i15<=n;i15++)
																	for(int i16=i15+1;i16<=n;i16++)
																		for(int i17=i16+1;i17<=n;i17++)
																			for(int i18=i17+1;i18<=n;i18++)
																				for(int i19=i18+1;i19<=n;i19++)
																				{
																					int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),a[i15]),a[i16]),a[i17]),a[i18]),a[i19]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17]+a[i18]+a[i19];
																					if(sum>(mx*2)) ans++;
																				}
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												for(int i11=i10+1;i11<=n;i11++)
													for(int i12=i11+1;i12<=n;i12++)
														for(int i13=i12+1;i13<=n;i13++)
															for(int i14=i13+1;i14<=n;i14++)
																for(int i15=i14+1;i15<=n;i15++)
																	for(int i16=i15+1;i16<=n;i16++)
																		for(int i17=i16+1;i17<=n;i17++)
																			for(int i18=i17+1;i18<=n;i18++)
																				for(int i19=i18+1;i19<=n;i19++)
																					for(int i20=i19+1;i20<=n;i20++)
																					{
																						int mx=max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i1],a[i2]),a[i3]),a[i4]),a[i5]),a[i6]),a[i7]),a[i8]),a[i9]),a[i10]),a[i11]),a[i12]),a[i13]),a[i14]),a[i15]),a[i16]),a[i17]),a[i18]),a[i19]),a[i20]),sum=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]+a[i16]+a[i17]+a[i18]+a[i19]+a[i20];
																						if(sum>(mx*2)) ans++;
																					}
		printf("%d\n",ans);
		return 0;
	}
  	return 0;
}
