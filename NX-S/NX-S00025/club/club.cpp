#include<bits/stdc++.h>
using namespace std;

struct data
{
	int index, satisfy;
};
struct moredata
{
	int id, satisfy;
};

struct member
{
	queue<data> list;
	int id;
};

member peo[100001];
moredata peo1[100001];
moredata peo2[100001];
moredata peo3[100001];
int sn1 = 0, sn2 = 0, sn3 = 0, sf1 = 0, sf2 = 0, sf3 = 0;

bool cmp1(data a1, data a2)
{
	return a1.satisfy >= a2.satisfy;
}

void input(int n)
{
	data s[4];
	for (int i = 1; i <= n; i++)
	{
		peo[i].id = i;
		for (int j = 1; j <= 3; j++)
		{
			cin >> s[j].satisfy;
			s[j].index = j;
		}
		sort(s + 1, s + 4, cmp1);
		for (int q = 1; q <= 3; q++)
			peo[i].list.push({s[q].index,s[q].satisfy});
	}
}

bool cmp2(moredata a1, moredata a2)
{
	return a1.satisfy >= a2.satisfy;
}

int deal(int n)
{
	sn1 = 0, sn2 = 0, sn3 = 0, sf1 = 0, sf2 = 0, sf3 = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (peo[i].list.front().index == 1)
		{
			sn1++;
			peo1[sn1].id = peo[i].id;
			peo1[sn1].satisfy = peo[i].list.front().satisfy;
		}
	}
	if (sn1 > n/2)
	{
		sort(peo1+1,peo1+sn1+1,cmp2);
		for (int i = n/2 + 1; i <= sn1; i++)
		{
			peo[peo1[i].id].list.pop();
		}
		sn1 = n/2;
	}
	for (int i = 1; i <= sn1; i++)
	{
		sf1 += peo1[i].satisfy;
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		if (peo[i].list.front().index == 2)
		{
			sn2++;
			peo2[sn2].id = peo[i].id;
			peo2[sn2].satisfy = peo[i].list.front().satisfy;
		}
	}
	if (sn2 > n/2)
	{
		sort(peo2+1,peo2+sn2+1,cmp2);
		for (int i = n/2 + 1; i <= sn2; i++)
		{
			peo[peo2[i].id].list.pop();
		}
		sn2 = n/2;
	}
	for (int i = 1; i <= sn2; i++)
	{
		sf2 += peo2[i].satisfy;
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		if (peo[i].list.front().index == 3)
		{
			sn3++;
			peo3[sn3].id = peo[i].id;
			peo3[sn3].satisfy = peo[i].list.front().satisfy;
		}
	}
	if (sn3 > n/2)
	{
		sort(peo3+1,peo3+sn3+1,cmp2);
		for (int i = n/2 + 1; i <= sn3; i++)
		{
			peo[peo3[i].id].list.pop();
		}
		sn3 = n/2;
	}
	for (int i = 1; i <= sn3; i++)
	{
		sf3 += peo3[i].satisfy;
	}
	
	return sf1 + sf2 + sf3;
		
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i++)
		{
			if (!(peo[i].list.empty()))
			{
				while (!(peo[i].list.empty()))
				{
					peo[i].list.pop();
				}
			}
		}
		
		input(n);
		cout << deal(n) << endl;
		
	}
		
	return 0;
}
