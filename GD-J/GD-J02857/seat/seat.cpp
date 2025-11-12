#include<bits/stdc++.h>
using namespace std;
int n,m,w,R;
int a[1100];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				w++;
				if(a[w]==R)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		else
			for(int j=n;j>=1;j--)
			{
				w++;
				if(a[w]==R)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
	return 0;
}
/*
正解满分拿下(·—·)
掌声在哪里？？
测评机别给我打脸啊(￣ε(#￣) 
初赛的时候，我S组只差1分到晋级线/(ㄒoㄒ)/~~
emm~没进提高组复赛是不是相当于省了五百多呢(lll￢ω￢) 
但我的同学很多都进了啊
我怎么记得我老师说过可以带零食进考场，怎么现在不给带啊
*/ 
