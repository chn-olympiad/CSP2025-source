#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int a[n + 5];
	for(int i = 1;i <= n; ++ i)
	{
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	int sum = 0;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	if(n == 2)
	{
		cout << 0;
		return 0;
	}
	if(n == 3)
	{
		int num = a[1] + a[2] + a[3];
		if(num > a[3] * 2) cout << 1;
		else cout << 0;
		return 0;
	}
	if(n == 4)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
	}
	if(n == 5)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 3; ++ i)
		{
			for(int j = i + 1;j < n - 2; ++ j)
			{
				for(int h = j + 1;h < n - 1; ++ h)
				{
					for(int w = h + 1;w < n; ++ w)
					{
						for(int u = w + 1;u <= n; ++ u)
						{
							int num = a[i] + a[j] + a[h] + a[w] + a[u];
							if(num > a[u] * 2)
							{
								sum ++;
							}
						}
					}
				}
			}
		}
	}
	if(n == 6)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 3; ++ i)
		{
			for(int j = i + 1;j < n - 2; ++ j)
			{
				for(int h = j + 1;h < n - 1; ++ h)
				{
					for(int w = h + 1;w < n; ++ w)
					{
						for(int u = w + 1;u <= n; ++ u)
						{
							int num = a[i] + a[j] + a[h] + a[w] + a[u];
							if(num > a[u] * 2)
							{
								sum ++;
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 4; ++ i)
		{
			for(int j = i + 1;j < n - 3; ++ j)
			{
				for(int h = j + 1;h < n - 2; ++ h)
				{
					for(int w = h + 1;w < n - 1; ++ w)
					{
						for(int u = w + 1;u < n; ++ u)
						{
							for(int x = u + 1;x <= n; ++ x)
							{
								int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x];
								if(num > a[x] * 2)
								{
									sum ++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n == 7)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 3; ++ i)
		{
			for(int j = i + 1;j < n - 2; ++ j)
			{
				for(int h = j + 1;h < n - 1; ++ h)
				{
					for(int w = h + 1;w < n; ++ w)
					{
						for(int u = w + 1;u <= n; ++ u)
						{
							int num = a[i] + a[j] + a[h] + a[w] + a[u];
							if(num > a[u] * 2)
							{
								sum ++;
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 4; ++ i)
		{
			for(int j = i + 1;j < n - 3; ++ j)
			{
				for(int h = j + 1;h < n - 2; ++ h)
				{
					for(int w = h + 1;w < n - 1; ++ w)
					{
						for(int u = w + 1;u < n; ++ u)
						{
							for(int x = u + 1;x <= n; ++ x)
							{
								int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x];
								if(num > a[x] * 2)
								{
									sum ++;
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 5; ++ i)
		{
			for(int j = i + 1;j < n - 4; ++ j)
			{
				for(int h = j + 1;h < n - 3; ++ h)
				{
					for(int w = h + 1;w < n - 2; ++ w)
					{
						for(int u = w + 1;u < n - 1; ++ u)
						{
							for(int x = u + 1;x < n; ++ x)
							{
								for(int l = x + 1;l <= n; ++ l)
								{
									int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l];
									if(num > a[l] * 2)
									{
										sum ++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n == 8)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 3; ++ i)
		{
			for(int j = i + 1;j < n - 2; ++ j)
			{
				for(int h = j + 1;h < n - 1; ++ h)
				{
					for(int w = h + 1;w < n; ++ w)
					{
						for(int u = w + 1;u <= n; ++ u)
						{
							int num = a[i] + a[j] + a[h] + a[w] + a[u];
							if(num > a[u] * 2)
							{
								sum ++;
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 4; ++ i)
		{
			for(int j = i + 1;j < n - 3; ++ j)
			{
				for(int h = j + 1;h < n - 2; ++ h)
				{
					for(int w = h + 1;w < n - 1; ++ w)
					{
						for(int u = w + 1;u < n; ++ u)
						{
							for(int x = u + 1;x <= n; ++ x)
							{
								int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x];
								if(num > a[x] * 2)
								{
									sum ++;
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 5; ++ i)
		{
			for(int j = i + 1;j < n - 4; ++ j)
			{
				for(int h = j + 1;h < n - 3; ++ h)
				{
					for(int w = h + 1;w < n - 2; ++ w)
					{
						for(int u = w + 1;u < n - 1; ++ u)
						{
							for(int x = u + 1;x < n; ++ x)
							{
								for(int l = x + 1;l <= n; ++ l)
								{
									int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l];
									if(num > a[l] * 2)
									{
										sum ++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 6; ++ i)
		{
			for(int j = i + 1;j < n - 5; ++ j)
			{
				for(int h = j + 1;h < n - 4; ++ h)
				{
					for(int w = h + 1;w < n - 3; ++ w)
					{
						for(int u = w + 1;u < n - 2; ++ u)
						{
							for(int x = u + 1;x < n - 1; ++ x)
							{
								for(int l = x + 1;l < n; ++ l)
								{
									for(int k = l + 1;k <= n; ++ k)
									{
										int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l] + a[k];
										if(num > a[k] * 2)
										{
											sum ++;
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
	if(n == 9)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 3; ++ i)
		{
			for(int j = i + 1;j < n - 2; ++ j)
			{
				for(int h = j + 1;h < n - 1; ++ h)
				{
					for(int w = h + 1;w < n; ++ w)
					{
						for(int u = w + 1;u <= n; ++ u)
						{
							int num = a[i] + a[j] + a[h] + a[w] + a[u];
							if(num > a[u] * 2)
							{
								sum ++;
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 4; ++ i)
		{
			for(int j = i + 1;j < n - 3; ++ j)
			{
				for(int h = j + 1;h < n - 2; ++ h)
				{
					for(int w = h + 1;w < n - 1; ++ w)
					{
						for(int u = w + 1;u < n; ++ u)
						{
							for(int x = u + 1;x <= n; ++ x)
							{
								int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x];
								if(num > a[x] * 2)
								{
									sum ++;
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 5; ++ i)
		{
			for(int j = i + 1;j < n - 4; ++ j)
			{
				for(int h = j + 1;h < n - 3; ++ h)
				{
					for(int w = h + 1;w < n - 2; ++ w)
					{
						for(int u = w + 1;u < n - 1; ++ u)
						{
							for(int x = u + 1;x < n; ++ x)
							{
								for(int l = x + 1;l <= n; ++ l)
								{
									int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l];
									if(num > a[l] * 2)
									{
										sum ++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 6; ++ i)
		{
			for(int j = i + 1;j < n - 5; ++ j)
			{
				for(int h = j + 1;h < n - 4; ++ h)
				{
					for(int w = h + 1;w < n - 3; ++ w)
					{
						for(int u = w + 1;u < n - 2; ++ u)
						{
							for(int x = u + 1;x < n - 1; ++ x)
							{
								for(int l = x + 1;l < n; ++ l)
								{
									for(int k = l + 1;k <= n; ++ k)
									{
										int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l] + a[k];
										if(num > a[k] * 2)
										{
											sum ++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 7; ++ i)
		{
			for(int j = i + 1;j < n - 6; ++ j)
			{
				for(int h = j + 1;h < n - 5; ++ h)
				{
					for(int w = h + 1;w < n - 4; ++ w)
					{
						for(int u = w + 1;u < n - 3; ++ u)
						{
							for(int x = u + 1;x < n - 2; ++ x)
							{
								for(int l = x + 1;l < n - 1; ++ l)
								{
									for(int k = l + 1;k < n; ++ k)
									{
										for(int r = k + 1;r <= n; ++ r)
										{
											int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l] + a[k] + a[r];
											if(num > a[r] * 2)
											{
												sum ++;
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
	if(n == 10)
	{
		for(int i = 1;i < n - 1; ++ i)
		{
			for(int j = i + 1;j < n; ++ j)
			{
				for(int h = j + 1;h <= n; ++ h)
				{
					int num = a[i] + a[j] + a[h];
					if(num > a[h] * 2)
					{
						sum ++;
					}
				}
			}
		}
		for	(int i = 1;i < n - 2; ++ i)
		{
			for(int j = i + 1;j < n - 1; ++ j)
			{
				for(int h = j + 1;h < n; ++ h)
				{
					for(int w = h + 1;w <= n; ++ w)
					{
						int num = a[i] + a[j] + a[h] + a[w];
						if(num > a[w] * 2)
						{
							sum ++;
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 3; ++ i)
		{
			for(int j = i + 1;j < n - 2; ++ j)
			{
				for(int h = j + 1;h < n - 1; ++ h)
				{
					for(int w = h + 1;w < n; ++ w)
					{
						for(int u = w + 1;u <= n; ++ u)
						{
							int num = a[i] + a[j] + a[h] + a[w] + a[u];
							if(num > a[u] * 2)
							{
								sum ++;
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 4; ++ i)
		{
			for(int j = i + 1;j < n - 3; ++ j)
			{
				for(int h = j + 1;h < n - 2; ++ h)
				{
					for(int w = h + 1;w < n - 1; ++ w)
					{
						for(int u = w + 1;u < n; ++ u)
						{
							for(int x = u + 1;x <= n; ++ x)
							{
								int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x];
								if(num > a[x] * 2)
								{
									sum ++;
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 5; ++ i)
		{
			for(int j = i + 1;j < n - 4; ++ j)
			{
				for(int h = j + 1;h < n - 3; ++ h)
				{
					for(int w = h + 1;w < n - 2; ++ w)
					{
						for(int u = w + 1;u < n - 1; ++ u)
						{
							for(int x = u + 1;x < n; ++ x)
							{
								for(int l = x + 1;l <= n; ++ l)
								{
									int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l];
									if(num > a[l] * 2)
									{
										sum ++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 6; ++ i)
		{
			for(int j = i + 1;j < n - 5; ++ j)
			{
				for(int h = j + 1;h < n - 4; ++ h)
				{
					for(int w = h + 1;w < n - 3; ++ w)
					{
						for(int u = w + 1;u < n - 2; ++ u)
						{
							for(int x = u + 1;x < n - 1; ++ x)
							{
								for(int l = x + 1;l < n; ++ l)
								{
									for(int k = l + 1;k <= n; ++ k)
									{
										int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l] + a[k];
										if(num > a[k] * 2)
										{
											sum ++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i = 1;i < n - 7; ++ i)
		{
			for(int j = i + 1;j < n - 6; ++ j)
			{
				for(int h = j + 1;h < n - 5; ++ h)
				{
					for(int w = h + 1;w < n - 4; ++ w)
					{
						for(int u = w + 1;u < n - 3; ++ u)
						{
							for(int x = u + 1;x < n - 2; ++ x)
							{
								for(int l = x + 1;l < n - 1; ++ l)
								{
									for(int k = l + 1;k < n; ++ k)
									{
										for(int r = k + 1;r <= n; ++ r)
										{
											int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l] + a[k] + a[r];
											if(num > a[r] * 2)
											{
												sum ++;
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
		for(int i = 1;i < n - 8; ++ i)
		{
			for(int j = i + 1;j < n - 7; ++ j)
			{
				for(int h = j + 1;h < n - 6; ++ h)
				{
					for(int w = h + 1;w < n - 5; ++ w)
					{
						for(int u = w + 1;u < n - 4; ++ u)
						{
							for(int x = u + 1;x < n - 3; ++ x)
							{
								for(int l = x + 1;l < n - 2; ++ l)
								{
									for(int k = l + 1;k < n - 1; ++ k)
									{
										for(int r = k + 1;r < n; ++ r)
										{
											for(int ans = r + 1;ans <= n; ++ ans)
											{
												int num = a[i] + a[j] + a[h] + a[w] + a[u] + a[x] + a[l] + a[k] + a[r] + a[ans];
												if(num > a[ans] * 2)
												{
													sum ++;
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
	cout << sum;
	return 0;
}
