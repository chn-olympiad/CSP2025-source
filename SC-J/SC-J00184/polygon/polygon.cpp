#include<bits/stdc++.h>
using namespace std;
int OI,AFO[5555],Right=0;
const int CSP=998244353;
void Train(int now,int last,int future,int real,bool do_something)
{
	if(last>future+future&&do_something)Right++;
	if(now>OI)return ;
	Right%=CSP;
	Train(now+1,last+AFO[now],max(future,AFO[now]),real+1,1);
	Train(now+1,last,future,real,0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>OI;
	for(int Luogu=1;Luogu<=OI;Luogu++)cin>>AFO[Luogu];
	Train(1,0,0,0,0);
	cout<<Right;
	return 0;
}