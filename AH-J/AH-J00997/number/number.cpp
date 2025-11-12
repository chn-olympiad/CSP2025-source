#include<bits/stdc++.h>

using namespace std;

const int N = 100001;
long long b[N],j = 0,re;
char c[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	long long sz = a.size();
	for(int i = 0;i < sz;i++)
	{
		c[i] = a[i];
	}
	for(int i = 0;i < sz;i++)
	{
		switch(c[i])
		{
			case '0':
				b[j] = 0;
				j++;
				break;
			case '1':
				b[j] = 1;
				j++;
				break;
			case '2':
				b[j] = 2;
				j++;
				break;
			case '3':
				b[j] = 3;
				j++;
				break;
			case '4':
				b[j] = 4;
				j++;
				break;
			case '5':
				b[j] = 5;
				j++;
				break;
			case '6':
				b[j] = 6;
				j++;
				break;
			case '7':
				b[j] = 7;
				j++;
				break;
			case '8':
				b[j] = 8;
				j++;
				break;
			case '9':
				b[j] = 9;
				j++;
				break;
		}
	}
	for(int i = 0;i < j;i++)
	{
		int max = -1;
		for(int k = i;k < j;k++)
		{
			if(b[k] >= max)
			{
				max = b[k];
				re = k;
			}
		}
		swap(b[i],b[re]);
	}
	for(int i = 0;i < j;i++)
	{
		cout << b[i];
	}
	
	return 0;
}
//Segmentation fault (core dumped)
