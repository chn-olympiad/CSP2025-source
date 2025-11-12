#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001][5];
int cnt = 0;
int t[100001] = {};
int maxx(int x,int y,int z){
	int t = max(x,y);
	t = max(t,z);
	return t;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n,m;
	cin >> m;
	for(int l=0;l<m;l++){
		cin >> n;
		long long ans = 0;
		int cnt[4] = {};
		for(int i=0;i<n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxp = maxx(a[i][1],a[i][2],a[i][3]);
			if(maxp == a[i][1])t[i] = 1;
			else if(maxp == a[i][2])t[i] = 2;
			else t[i] = 3;
			cnt[t[i]]++;
		}
	
		if(cnt[1] <= (n/2) && cnt[2] <= (n/2) && cnt[3] <= (n/2))
		{
			
		}
		else
		{
			int maxc;
			while(cnt[1] > (n/2) || cnt[2] > (n/2) || cnt[3] > (n/2))
			{
				//cout << 11 << endl;
				int maxt = maxx(cnt[1],cnt[2],cnt[3]);
				int maxnum = 0;
				if(maxt == cnt[1])maxnum = 1;
				else if(maxt == cnt[2])maxnum = 2;
				else maxnum = 3;
				int need = maxt - (n/2);
			//	cout << maxt << ' ' << n << endl;
			//	cout << maxnum << endl;
		//	cout << need << endl;
				int change[need+1] = {},changeto[need+1] = {},name[need+1] = {};
				for(int ttt = 0;ttt<=need;ttt++)
				{
					change[ttt] = 10000001;
				}
//				for(int q=0;q<need;q++)
//				{
//					cout << q << ' ' << change[q] << endl;
//				}
				
				int changet;
				int tc[need];
					for(int r=0;r<need;r++)
								{
									tc[r] = 10000001;
								}
				for(int i=0;i<n;i++)
				{
				//	cout << i << ' ' << maxnum << endl;
					if(maxx(a[i][1],a[i][2],a[i][3]) == a[i][maxnum])
					{
					//	cout << i << endl;
						if(maxnum == 1)
						{
							changet = min(a[i][maxnum]-a[i][2],a[i][maxnum]-a[i][3]);
							if(changet == a[i][maxnum]-a[i][2])
							{
							
							
							
								for(int w=0;w<need;w++)
								{
									for(int p=need-1;p>=w;p--)
									{
										if(tc[p]<tc[p-1])swap(tc[p],tc[p-1]);
									}
								}
							//	cout << tc[0] << endl;
								bool b = 0;
								for(int f=need-1;f>=0;f--)
								{
									if(tc[f] == 10000001)
									{
										b = 1;break;
									}
								}
								//cout << b <<endl;
								for(int j=need-1;j>=0;j--)
								{
									if(changet < tc[j])
									{
										
										
										
									//	cout << "wr" << endl;
										for(int u=need-1;u>=0;u--)
										{
											
												
													if(change[u] == tc[j])
													{
														name[u] = i;
												change[u] = changet;
												tc[j] = changet;
												break;
													}
												}
												
											
										}
										break;
						
								}
							}
							else if(changet == a[i][maxnum]-a[i][3])
							{
							
								for(int w=0;w<need;w++)
								{
									for(int p=need-1;p>=w;p--)
									{
										if(tc[p]<tc[p-1])swap(tc[p],tc[p-1]);
									}
								}
							//	cout << tc[0] << endl;
								bool b = 0;
								for(int f=need-1;f>=0;f--)
								{
									if(tc[f] == 10000001)
									{
										b = 1;break;
									}
								}
								//cout << b <<endl;
								for(int j=need-1;j>=0;j--)
								{
									if(changet < tc[j])
									{
										
										
										
									//	cout << "wr" << endl;
										for(int u=need-1;u>=0;u--)
										{
											
												
													if(change[u] == tc[j])
													{
														name[u] = i;
												change[u] = changet;
												tc[j] = changet;
												break;
													}
												}
												
											
										}
										break;
						
								}
							}
						}
						if(maxnum == 2)
						{
							changet = min(a[i][maxnum]-a[i][1],a[i][maxnum]-a[i][3]);
						//	cout << changet << endl;
							if(changet == a[i][maxnum]-a[i][1])
							{
							
							
								for(int w=0;w<need;w++)
								{
									for(int p=need-1;p>=w;p--)
									{
										if(tc[p]<tc[p-1])swap(tc[p],tc[p-1]);
									}
								}
							//	cout << tc[0] << endl;
								bool b = 0;
								for(int f=need-1;f>=0;f--)
								{
									if(tc[f] == 10000001)
									{
										b = 1;break;
									}
								}
								//cout << b <<endl;
								for(int j=need-1;j>=0;j--)
								{
									if(changet < tc[j])
									{
										
										
										
									//	cout << "wr" << endl;
										for(int u=need-1;u>=0;u--)
										{
											
												
													if(change[u] == tc[j])
													{
														name[u] = i;
												change[u] = changet;
												tc[j] = changet;
												break;
													}
												}
												
											
										}
										break;
						
								}
							}
							else if(changet == a[i][maxnum]-a[i][3])
							{
								
							
								for(int w=0;w<need;w++)
								{
									for(int p=need-1;p>=w;p--)
									{
										if(tc[p]<tc[p-1])swap(tc[p],tc[p-1]);
									}
								}
							//	cout << tc[0] << endl;
								bool b = 0;
								for(int f=need-1;f>=0;f--)
								{
									if(tc[f] == 10000001)
									{
										b = 1;break;
									}
								}
								//cout << b <<endl;
								for(int j=need-1;j>=0;j--)
								{
									if(changet < tc[j])
									{
										
										
										
									//	cout << "wr" << endl;
										for(int u=need-1;u>=0;u--)
										{
											
												
													if(change[u] == tc[j])
													{
														name[u] = i;
												change[u] = changet;
												tc[j] = changet;
												break;
													}
												}
												
											
										}
										break;
						
								}
						
								
							}
						//	cout << 11 << endl;
						}
						if(maxnum == 3)
						{
							changet = min(a[i][maxnum]-a[i][2],a[i][maxnum]-a[i][1]);
							if(changet == a[i][maxnum]-a[i][2])
							{
								
						//	cout << changet << endl;
							
								for(int w=0;w<need;w++)
								{
									for(int p=need-1;p>=w;p--)
									{
										if(tc[p]<tc[p-1])swap(tc[p],tc[p-1]);
									}
								}
							//	cout << tc[0] << endl;
								bool b = 0;
								for(int f=need-1;f>=0;f--)
								{
									if(tc[f] == 10000001)
									{
										b = 1;break;
									}
								}
								//cout << b <<endl;
								for(int j=need-1;j>=0;j--)
								{
									if(changet < tc[j])
									{
										
										
										
									//	cout << "wr" << endl;
										for(int u=need-1;u>=0;u--)
										{
											
												
													if(change[u] == tc[j])
													{
														name[u] = i;
												change[u] = changet;
												tc[j] = changet;
												break;
													}
												}
												
											
										}
										break;
						
								}
							}
							else if(changet == a[i][maxnum]-a[i][1])
							{
							
						//	cout << 13 << endl;
								for(int w=0;w<need;w++)
								{
									for(int p=need-1;p>=w;p--)
									{
										if(tc[p]<tc[p-1])swap(tc[p],tc[p-1]);
									}
								}
							//	cout << tc[0] << endl;
								bool b = 0;
								for(int f=need-1;f>=0;f--)
								{
									if(tc[f] == 10000001)
									{
										b = 1;break;
									}
								}
								//cout << b <<endl;
								for(int j=need-1;j>=0;j--)
								{
									if(changet < tc[j])
									{
										
										
										
									//	cout << "wr" << endl;
										for(int u=need-1;u>=0;u--)
										{
											
												
													if(change[u] == tc[j])
													{
														name[u] = i;
												change[u] = changet;
												tc[j] = changet;
												break;
													}
												}
												
											
										}
										break;
						
								}
								
							}
						}
						
						
					}
			}
				
				for(int k=0;k<need;k++)
				{
					//cout << name[k] << ' ' << change[k] << endl;
					a[name[k]][maxnum] = 0;
				//	cout << "sa" << endl;
					
					
				}
				for(int i=1;i<=3;i++)
				{
					cnt[i] = 0;
				}
				for(int i=0;i<n;i++)
				{
				//	cout << a[i][1] << ' ' << a[i][2] << ' ' << a[i][3] << endl;
					int maxp = maxx(a[i][1],a[i][2],a[i][3]);
					if(maxp == a[i][1])t[i] = 1;
					else if(maxp == a[i][2])t[i] = 2;
					else t[i] = 3;
					cnt[t[i]]++;
				//	cout << t[i] << endl;
				}
				
			
		
			
		}
			
		
	} for(int i=0;i<n;i++)
			{
				ans += maxx(a[i][1],a[i][2],a[i][3]);
			}
	cout << ans << endl;
}
	return 0;
 } 
 /*
 5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522





10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107
*/
