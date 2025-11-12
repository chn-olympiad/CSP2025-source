#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n,m,tmp,hang,lie;
struct cj
{
	bool is_pd;
	int score;
}j[114514];
void tiaoshi()
{
	for(int i=1;i<=n*m;i++)
	{
		cout<<j[i].score<<' ';
	}
}
bool cmp(cj k,cj l)
{
	if(k.score>l.score)
		return true;
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		cin>>j[i].score;
	}
	j[1].is_pd=true;
	stable_sort(j+1,j+1+n*m,cmp);
	tmp=1;
	while(j[tmp].is_pd!=true)
	{
		tmp++;
	}
	lie=ceil(tmp*1.0/n);
	if(lie%2)
	{
		hang=tmp%n;
		if(hang==0)
			hang=n;
	}
	else
		hang=m-(tmp%n)+1;
	printf("%d %d",lie,hang);
	//tiaoshi();
	
}
