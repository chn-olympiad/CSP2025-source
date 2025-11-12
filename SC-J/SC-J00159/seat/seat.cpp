#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int MAXNM = 128;
int marks[MAXNM];
bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d", &marks[i]);
	}
	int r_mark=marks[1];
	sort(marks+1, marks+1+n*m, cmp);
	int r_pos = 1;
	/*for(int i=1;i<=n*m;i++)
	{
		if(marks[i] == r_mark)
		{
			r_pos = i;
			break;
		}
	}*/
	//cout<<"debug -- "<<r_pos<<endl;
	int pos = 1;
	for(int i=1;i<=m;i++)
	{
		if(i%2 == 1)
		{
			for(int j=1;j<=n;j++)
			{
				if(marks[pos] == r_mark)
				{
					printf("%d %d", i, j);
				}
				pos++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(marks[pos] == r_mark)
				{
					printf("%d %d", i, j);
				}
				pos++;
			}
		}
	}
/*	int l = r_pos / n;  // 刚好 %n == 0 || %n != 0
	
	if (r_pos % n != 0)
	{
		l+=1;
	} 
	int h = r_pos % n;
	h+=1;
	if (l % 2 == 1) // 逆向上升 
	{
		h = n-h;
	}
	printf("%d %d", l, h);*/
	return 0;
} 