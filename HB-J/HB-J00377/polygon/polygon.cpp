#include<bits/stdc++.h>
using namespace std;
int n,arr[5005],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	if(n==3)
	{
		if(arr[1]+arr[2]+arr[3]>arr[3]*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(n==4)
	{
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
					}
				}
			}
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]>arr[4]*2)
		{
			sum++;
		}
	}
	if(n==5)
	{
		for(int a=1;a<=3;a++)
		{
			for(int b=2;b<=4;b++)
			{
				for(int c=3;c<=5;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
						//printf("a=%d b=%d c=%d\n",a,b,c);
						//cout<<1<<endl;
					}
				}
			}
		}
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					for(int d=4;d<=5;d++)
					{
						if(arr[a]+arr[b]+arr[c]+arr[d]>arr[d]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d)
						{
							//printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);
							sum++;
							//cout<<2<<endl;
						}
					}
				}
			}
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]>arr[5]*2)
		{
			sum++;
		}
	}
	if(n==6)
	{
		for(int a=1;a<=4;a++)
		{
			for(int b=2;b<=5;b++)
			{
				for(int c=3;c<=6;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
					}
				}
			}
		}
		for(int a=1;a<=3;a++)
		{
			for(int b=2;b<=4;b++)
			{
				for(int c=3;c<=5;c++)
				{
					for(int d=4;d<=6;d++)
					{
						if(arr[a]+arr[b]+arr[c]+arr[d]>arr[d]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d)
						{
							sum++;
						}
					}
				}
			}
		}
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					for(int d=4;d<=5;d++)
					{
						for(int e=5;e<=6;e++)
						{
							if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]>arr[e]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e)
							{
								sum++;
							}
						}
					}
				}
			}
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]>arr[6]*2)
		{
			sum++;
		}
	}
	if(n==7)
	{
		for(int a=1;a<=5;a++)
		{
			for(int b=2;b<=6;b++)
			{
				for(int c=3;c<=7;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
					}
				}
			}
		}
		for(int a=1;a<=4;a++)
		{
			for(int b=2;b<=5;b++)
			{
				for(int c=3;c<=6;c++)
				{
					for(int d=4;d<=7;d++)
					{
						if(arr[a]+arr[b]+arr[c]+arr[d]>arr[d]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d)
						{
							sum++;
						}
					}
				}
			}
		}
		for(int a=1;a<=3;a++)
		{
			for(int b=2;b<=4;b++)
			{
				for(int c=3;c<=5;c++)
				{
					for(int d=4;d<=6;d++)
					{
						for(int e=5;e<=7;e++)
						{
							if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]>arr[e]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e)
							{
								sum++;
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					for(int d=4;d<=5;d++)
					{
						for(int e=5;e<=6;e++)
						{
							for(int f=6;f<=7;f++)
							{
								if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]>arr[f]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f)
								{
									sum++;
								}
							}
						}
					}
				}
			}
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]>arr[7]*2)
		{
			sum++;
		}
	}
	if(n==8)
	{
		for(int a=1;a<=6;a++)
		{
			for(int b=2;b<=7;b++)
			{
				for(int c=3;c<=8;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
					}
				}
			}
		}
		for(int a=1;a<=5;a++)
		{
			for(int b=2;b<=6;b++)
			{
				for(int c=3;c<=7;c++)
				{
					for(int d=4;d<=8;d++)
					{
						if(arr[a]+arr[b]+arr[c]+arr[d]>arr[d]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d)
						{
							sum++;
						}
					}
				}
			}
		}
		for(int a=1;a<=4;a++)
		{
			for(int b=2;b<=5;b++)
			{
				for(int c=3;c<=6;c++)
				{
					for(int d=4;d<=7;d++)
					{
						for(int e=5;e<=8;e++)
						{
							if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]>arr[e]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e)
							{
								sum++;
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=3;a++)
		{
			for(int b=2;b<=4;b++)
			{
				for(int c=3;c<=5;c++)
				{
					for(int d=4;d<=6;d++)
					{
						for(int e=5;e<=7;e++)
						{
							for(int f=6;f<=8;f++)
							{
								if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]>arr[f]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f)
								{
									sum++;
								}
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					for(int d=4;d<=5;d++)
					{
						for(int e=5;e<=6;e++)
						{
							for(int f=6;f<=7;f++)
							{
								for(int g=7;g<=8;g++)
								{
									if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]>arr[g]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f&&a<g&&b<g&&c<g&&d<g&&e<g&&f<g)
									{
										sum++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]>arr[8]*2)
		{
			sum++;
		}
	}
	if(n==9)
	{
		for(int a=1;a<=7;a++)
		{
			for(int b=2;b<=8;b++)
			{
				for(int c=3;c<=9;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
					}
				}
			}
		}
		for(int a=1;a<=6;a++)
		{
			for(int b=2;b<=7;b++)
			{
				for(int c=3;c<=8;c++)
				{
					for(int d=4;d<=9;d++)
					{
						if(arr[a]+arr[b]+arr[c]+arr[d]>arr[d]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d)
						{
							sum++;
						}
					}
				}
			}
		}
		for(int a=1;a<=5;a++)
		{
			for(int b=2;b<=6;b++)
			{
				for(int c=3;c<=7;c++)
				{
					for(int d=4;d<=8;d++)
					{
						for(int e=5;e<=9;e++)
						{
							if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]>arr[e]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e)
							{
								sum++;
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=4;a++)
		{
			for(int b=2;b<=5;b++)
			{
				for(int c=3;c<=6;c++)
				{
					for(int d=4;d<=7;d++)
					{
						for(int e=5;e<=8;e++)
						{
							for(int f=6;f<=9;f++)
							{
								if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]>arr[f]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f)
								{
									sum++;
								}
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=3;a++)
		{
			for(int b=2;b<=4;b++)
			{
				for(int c=3;c<=5;c++)
				{
					for(int d=4;d<=6;d++)
					{
						for(int e=5;e<=7;e++)
						{
							for(int f=6;f<=8;f++)
							{
								for(int g=7;g<=9;g++)
								{
									if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]>arr[g]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f&&a<g&&b<g&&c<g&&d<g&&e<g&&f<g)
									{
										sum++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					for(int d=4;d<=5;d++)
					{
						for(int e=5;e<=6;e++)
						{
							for(int f=6;f<=7;f++)
							{
								for(int g=7;g<=8;g++)
								{
									for(int h=8;h<=9;h++)
									{
										if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]+arr[h]>arr[h]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f&&a<g&&b<g&&c<g&&d<g&&e<g&&f<g&&a<h&&b<h&&c<h&&d<h&&e<h&&f<h&&g<h)
										{
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]>arr[9]*2)
		{
			sum++;
		}
	}
	if(n==10)
	{
		for(int a=1;a<=8;a++)
		{
			for(int b=2;b<=9;b++)
			{
				for(int c=3;c<=10;c++)
				{
					if(arr[a]+arr[b]+arr[c]>arr[c]*2&&a!=b&&a!=c&&b!=c&&a<b&&a<c&&b<c)
					{
						sum++;
					}
				}
			}
		}
		for(int a=1;a<=7;a++)
		{
			for(int b=2;b<=8;b++)
			{
				for(int c=3;c<=9;c++)
				{
					for(int d=4;d<=10;d++)
					{
						if(arr[a]+arr[b]+arr[c]+arr[d]>arr[d]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d)
						{
							sum++;
						}
					}
				}
			}
		}
		for(int a=1;a<=6;a++)
		{
			for(int b=2;b<=7;b++)
			{
				for(int c=3;c<=8;c++)
				{
					for(int d=4;d<=9;d++)
					{
						for(int e=5;e<=10;e++)
						{
							if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]>arr[e]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e)
							{
								sum++;
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=5;a++)
		{
			for(int b=2;b<=6;b++)
			{
				for(int c=3;c<=7;c++)
				{
					for(int d=4;d<=8;d++)
					{
						for(int e=5;e<=9;e++)
						{
							for(int f=6;f<=10;f++)
							{
								if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]>arr[f]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f)
								{
									sum++;
								}
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=4;a++)
		{
			for(int b=2;b<=5;b++)
			{
				for(int c=3;c<=6;c++)
				{
					for(int d=4;d<=7;d++)
					{
						for(int e=5;e<=8;e++)
						{
							for(int f=6;f<=9;f++)
							{
								for(int g=7;g<=10;g++)
								{
									if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]>arr[g]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f&&a<g&&b<g&&c<g&&d<g&&e<g&&f<g)
									{
										sum++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=3;a++)
		{
			for(int b=2;b<=4;b++)
			{
				for(int c=3;c<=5;c++)
				{
					for(int d=4;d<=6;d++)
					{
						for(int e=5;e<=7;e++)
						{
							for(int f=6;f<=8;f++)
							{
								for(int g=7;g<=9;g++)
								{
									for(int h=8;h<=10;h++)
									{
										if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]+arr[h]>arr[h]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f&&a<g&&b<g&&c<g&&d<g&&e<g&&f<g&&a<h&&b<h&&c<h&&d<h&&e<h&&f<h&&g<h)
										{
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int a=1;a<=2;a++)
		{
			for(int b=2;b<=3;b++)
			{
				for(int c=3;c<=4;c++)
				{
					for(int d=4;d<=5;d++)
					{
						for(int e=5;e<=6;e++)
						{
							for(int f=6;f<=7;f++)
							{
								for(int g=7;g<=8;g++)
								{
									for(int h=8;h<=9;h++)
									{
										for(int i=9;i<=10;i++)
										{
											if(arr[a]+arr[b]+arr[c]+arr[d]+arr[e]+arr[f]+arr[g]+arr[h]+arr[i]>arr[i]*2&&a!=b&&a!=c&&b!=c&&a!=d&&b!=d&&c!=d&&a!=e&&b!=e&&c!=e&&d!=e&&a<b&&a<c&&b<c&&a<d&&b<d&&c<d&&a<e&&b<e&&c<e&&d<e&&a<f&&b<f&&c<f&&d<f&&e<f&&a<g&&b<g&&c<g&&d<g&&e<g&&f<g&&a<h&&b<h&&c<h&&d<h&&e<h&&f<h&&g<h&&a<i&&b<i&&c<i&&d<i&&e<i&&f<i&&g<i&&h<i)
											{
												sum++;
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
		
		if(arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]+arr[10]>arr[10]*2)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
