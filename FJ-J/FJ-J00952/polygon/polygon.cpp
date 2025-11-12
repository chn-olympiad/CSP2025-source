#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
long long s;
#define f(x, y, z) for (int x = y; x <= z; x++) 
int j(int x)
{
	int s = 1;
	for (int i = 1; i <= x; i++)
	{
		s *= i;
	}
	return s;
}
int C(int x, int y)
{
	return j(x) / j(x - y) / j(y);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n <= 3)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		if (b > c) swap(c, b);
		if (a > b) swap(a, b);
		if (a + b + c > 2 * c) cout << 1;
		else cout << 0;
	}
	else if (n <= 10)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if (n == 4)
		{
			f(i, 1, n)
				f(j, i, n)
					f(k, j, n)
						if (i + j + k > k * 2)
							s++;
			f(i, 1, n)
				f(j, i, n)
					f(k, j, n)
						f(l, k, n)
							if (i + j + k + l > l * 2)
								s++;
		}
		else if (n == 5)
		{
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						if (i + j + k > k * 2)
						{
							s++;
						}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							if (i + j + k + l > l * 2)
							{
								s++;
							}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								if (i + j + k + l + m > m * 2)
								{
									s++;
								}
		}
		else if (n == 6)
		{
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						if (i + j + k > k * 2)
						{
							s++;
						}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							if (i + j + k + l > l * 2)
							{
								s++;
							}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								if (i + j + k + l + m > m * 2)
								{
									s++;
								}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									if (i + j + k + l + m  + aa > aa * 2)
									{
										s++;
									}
		}
		else if (n == 7)
		{
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						if (i + j + k > k * 2)
						{
							s++;
						}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							if (i + j + k + l > l * 2)
							{
								s++;
							}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								if (i + j + k + l + m > m * 2)
								{
									s++;
								}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									if (i + j + k + l + m + aa > aa * 2)
									{
										s++;
									}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										if (i + j + k + l + m + aa + bb > bb * 2)
										{
											s++;
										}
		}
		else if (n == 8)
		{
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						if (i + j + k > k * 2)
						{
							s++;
						}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							if (i + j + k + l > l * 2)
							{
								s++;
							}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								if (i + j + k + l + m > m * 2)
								{
									s++;
								}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									if (i + j + k + l + m + aa > aa * 2)
									{
										s++;
									}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										if (i + j + k + l + m + aa + bb > bb * 2)
										{
											s++;
										}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										f(cc, bb + 1, n)
											if (i + j + k + l + m + aa + bb + cc > cc * 2)
											{
												s++;
											}
		}
		else if (n == 9)
		{
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						if (i + j + k > k * 2)
						{
							s++;
						}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							if (i + j + k + l > l * 2)
							{
								s++;
							}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								if (i + j + k + l + m > m * 2)
								{
									s++;
								}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									if (i + j + k + l + m + aa > aa * 2)
									{
										s++;
									}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										if (i + j + k + l + m + aa + bb > bb * 2)
										{
											s++;
										}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										f(cc, bb + 1, n)
											if (i + j + k + l + m + aa + bb + cc > cc * 2)
											{
												s++;
											}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										f(cc, bb + 1, n)
											f(dd, cc + 1, n)
												if (i + j + k + l + m + aa + bb + cc + dd > dd * 2)
												{
													s++;
												}
		}
		else if (n == 10)
		{
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						if (i + j + k > k * 2)
						{
							s++;
						}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							if (i + j + k + l > l * 2)
							{
								s++;
							}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								if (i + j + k + l + m > m * 2)
								{
									s++;
								}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									if (i + j + k + l + m + aa > aa * 2)
									{
										s++;
									}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										if (i + j + k + l + m + aa + bb > bb * 2)
										{
											s++;
										}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										f(cc, bb + 1, n)
											if (i + j + k + l + m + aa + bb + cc > cc * 2)
											{
												s++;
											}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										f(cc, bb + 1, n)
											f(dd, cc + 1, n)
												if (i + j + k + l + m + aa + bb + cc + dd > dd * 2)
												{
													s++;
													s %= 998244353;
												}
			f(i, 1, n)
				f(j, i + 1, n)
					f(k, j + 1, n)
						f(l, k + 1, n)
							f(m, l + 1, n)
								f(aa, m + 1, n)
									f(bb, aa + 1, n)
										f(cc, bb + 1, n)
											f(dd, cc + 1, n)
												f(ee, dd + 1, n)
												if (i + j + k + l + m + aa + bb + cc + dd + ee > ee * 2)
												{
													s++;
													s %= 998244353;
												}
		}
		cout << s % 998244353;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 3; i <= n; i++)
		{
			s += C(n, min(i, n - i));
			s %= 998244353;
		}
		cout << s % 998244353;
	}
}


/*
#iNcLuDe <sTd>
uSiNg nAmEsPaCe bItS/StDc++.H;
iNt MaIn()
{
	froepen("polygon.in", "w", stdout);
	froepen("polygon.out", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout<<"never gonna give you up";
	} 
	  hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
}*/
