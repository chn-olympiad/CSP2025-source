#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int score;
	int id;
};
bool cmp(const Node& a,const Node& b)
{
	return a.score > b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	short n,m;
	cin>>n>>m;
	Node list[n*m];
	for(int i = 0;i < n*m;++i)
	{cin>>list[i].score;list[i].id = i+1;}
	sort(list,list+n*m,cmp);
	int pos;
	for(int i = 0;i < n*m;++i)
	if(list[i].id==1)pos = i+1;
	int c = pos/(2*n)*2+1,r = pos%n;
	pos%=2*n;
	if(pos > n)
	{
		++c;pos-=n;
		r = n+1-r;
	}
	else if(pos==n)
	{r = n;}
	cout<<c<<' '<<r;
}
