#include<iostream>
#include<algorithm>
using namespace std;

int col,row;
int scores[100005];

bool cmp(int &a, int &b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>row>>col;
	int sts = row*col;
	for(int i=1;i<=sts;i++) cin>>scores[i];
	int R=scores[1];
	sort(scores+1,scores+sts+1,cmp);
	int id = 0;
	for(int i=1;i<=sts;i++)
	{
		if(scores[i]==R) 
		{
			id=i;
			break;
		}
	}
	if(id%row==0)
	{
		if(id/row%2==0) cout<<id/row<<" "<<1;
		else cout<<id/row<<" "<<row;
	}
	else
	{
		if(id/row%2==0) cout<<id/row+1<<" "<<id%row;
		else cout<<id/row+1<<" "<<(row-(id%row))+1;
	}
	return 0;
}

