#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pplCount;
	cin>>n>>m;
	pplCount=n*m;
	int a1,ai;
	for(int i=0;i<pplCount;i++)
	{
		cin>>ai;
		a.push_back(ai);
	} 
	a1=a[0];
	sort(a.begin(),a.begin()+pplCount-1);
	int index=0;
	while(a[index]!=a1)
	index++;
	index=pplCount-index;
	index--;
	int m1,n1,addition;
	if(index%n==0)
	m1=index/n;
	else
	m1=index/n+1;
	addition=index-n*(m1-1);
    if(m1%2!=0)
    n1=addition;
    else
    n1=n+1-addition;
    cout<<m1<<' '<<n1; 
	return 0;
}

