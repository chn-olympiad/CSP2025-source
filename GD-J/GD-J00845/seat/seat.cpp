#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;


unsigned int n;
unsigned int m;
unsigned int nxm;
unsigned int temp;
unsigned int bucket[101];
unsigned int rank1;
unsigned int xm;
unsigned int x = 1;
unsigned int y = 1;
bool direction1 = false; 


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%u%u",&n,&m);
	nxm = n * m;
	for (int i = 1;i <= nxm;i++)
	{
		scanf("%u",&temp);
		if (i == 1) xm = temp;
		bucket[temp]++;
	}
	for (int i = 100;i >= 0;i--)
	{
		rank1 += bucket[i];
		if (i == xm)
		{
			break;
		} 
	}
	for (int i = 1;i < rank1;i++)
	{
		if (!direction1)
		{
			x++;
		}
		else
		{
			x--;
		}
		if (x == n + 1)
		{
			direction1 = true;
			x--;
			y++;
		}
		if (x == 0)
		{
			direction1 = false;
			x++;
			y++;
		}
	}
	printf("%u %u",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

// 456
