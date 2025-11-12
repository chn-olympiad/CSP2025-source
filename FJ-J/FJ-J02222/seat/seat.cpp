#include<bits/stdc++.h>
using namespace std;
struct student
{
	int score;
	bool type;
}a[105];
bool cmp(student a,student b){return a.score > b.score;}
int get_seat(int rank,int n,int m,bool type)
{
	int x = ceil(rank/(double)n);
	if(type) return x;
	int y = 0;
	if(x%2 == 1) y = (rank%n == 0) ? n:(rank%n);
	else y = (rank%n == 0) ? 1:(n-(rank%n)+1);
	return y;
}
int n,m,ind;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;++i)
	{
		scanf("%d",&a[i].score);
		if(i == 1) a[i].type = 1;
		else a[i].type = 0;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i].type)
		{
			ind = i;
			break;
		}
	}
	printf("%d %d",get_seat(ind,n,m,1),get_seat(ind,n,m,0));
	return 0;
}
