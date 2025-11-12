#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v;
int n,t,ans=0;
void bfs()
{
	queue<int> qs,qn,qm,qp;
	qs.push(0);
	qn.push(1);
	qm.push(0);
	qp.push(0);
	while(!qs.empty())
	{
		int s=qs.front();
		int num=qn.front();
		int max=qm.front();
		int pos=qp.front();
		qs.pop();
		qn.pop();
		qm.pop();
		qp.pop();
		if(num>=3&&s>max) 
		{
			
			ans++;
		}
		int i=1;
		while(pos+i<=n) 
		{
			qs.push(s+max);
			qn.push(num+1);
			qm.push(v[pos+i]);
			qp.push(pos+i);
			i++;
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	v.push_back(0);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	bfs();
	printf("%d",ans%998%244%353);
	return 0;
}
