#include <bits/stdc++.h>
#define O 105
using namespace std;
int n,m,idx = 0,pos,row;
struct node
{
	int sco,id;
}	lst[O];
bool cmp(node n1,node n2)
{
	return n1.sco > n2.sco;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);	//n行m列 
	for(int i = 1;i <= n * m;++i)
		scanf("%d",&lst[i].sco),lst[i].id = i;
	sort(lst + 1,lst + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;++i)
	{
		if(lst[i].id == 1)
		{
			pos = i;
			break;
		}
	}
	while(idx < pos)
	{
		idx += n;	//行数增加 
		++row;	//列 
	}
	printf("%d ",row);
	if(row % 2)	//奇数列,小到大 
	{
		printf("%d",pos - n * (row - 1));
	}
	else	//偶数列,大到小 
	{
		printf("%d",m - (pos - n * (row - 1)) + 1);
	}
	return 0;
}
/*
2 2
98 99 100 97
pos = 3 
*/
