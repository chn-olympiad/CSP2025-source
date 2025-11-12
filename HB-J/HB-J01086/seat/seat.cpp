#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int sco[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	cin>>sco[1];
	int sco1=sco[1];
	for(int i=2;i<=t;i++)
	{
		cin>>sco[i];
	}
	int idx;
	sort(sco+1,sco+t+1);
	for(int i=t;i>=1;i--)
	{
		if(sco[i]==sco1)
		{
			idx=t+1-i;
			break;
		}
	}
	int x=idx/n,y=idx%n;
	if(x%2==1&&y==0)cout<<x<<' '<<n;
	else if(x%2==1&&y!=0)cout<<x+1<<' '<<n+1-y;
	else if(x%2==0&&y==0)cout<<x<<" 0";
	else cout<<x+1<<' '<<y;
	return 0;
}
