#include<bits/stdc++.h>
using namespace std;
int n,m,score[105],t,x,y;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>score[i];
	}
	t=score[1];
	sort(score+1,score+1+m*n,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(score[i]==t)
		{
			int tmod=i%(2*n);
			x=i/(2*n)*2;
			if(tmod==0)
			{
				y=1;
				break;
			}
			else
			{
				x++;
				if(tmod>n)x++;
			}
			if(tmod<=n)y=tmod;
			else y=2*n-tmod+1;
			break;
		}
	}
	cout<<x<<' '<<y;
	return 0;
 } 
