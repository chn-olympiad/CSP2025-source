#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


unsigned int n, k;
unsigned int xorsum;
unsigned int arr[500000];
unsigned int dbbs_index = 0; 
int last1 = -1;
unsigned int co = 0;

map<pair<int,int> ,int> m;


int findxor(int l,int r)
{
	//printf("XFIND %d %d\n",l,r);
	if (m.find({l,r}) != m.end())
	{
		//printf("XFIND already in db: %d\n",m[{l,r}]);
		return m[{l,r}]; 
	}
	//printf("XFIND cannot find, get last ");
	m[{l,r}] = findxor(l,r-1) ^ arr[r];
	//printf("XFIND now can find, it is %d",m[{l,r}]);
	
	return m[{l,r}];
}


inline void getxor(int index)
{
	//printf("XOR getxor for %d\n",index);
	m[{index,index}] = arr[index];
	//printf("XOR finding xor for %d\n",index);
	if (arr[index] == k)
	{
		last1 = index;
		//printf("%d %d\n",index,index);
		co++;
		return;
	}
	for (int i = index - 1;i > last1;i--)
	{
		//printf("XOR finding xor for %d %d\n",i,index);
		//printf("%d\n",findxor(i,index));
		if (findxor(i,index) == k)
		{
			// XOR FIND
			//printf("%d %d\n",i,index);
			last1 = index;
			co++;
			return;
		}
	}
}


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%u%u",&n,&k);
	for (int i = 0;i < n;i++)
	{
		scanf("%u",arr+i);
		getxor(i);
	}
	printf("%u",co);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

// 789
