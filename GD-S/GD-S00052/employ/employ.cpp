#include<bits/stdc++.h>
using namespace std;




struct P{
	int id;
	int c;
//	void sortp(int& oid,int& oc)
//	{
//		int t1=id;
//		int t2=c;
//		id=oid;
//		c=oc;
//		oid=t1;
//		oc=t2;
//	}
};
P p[505];
int qzhe[505];

bool cmp(P x,P y)
{
	return x.c<y.c;
}

int shunxu[505];

void search()
{
	
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string nd;
	cin>> nd;
	qzhe[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(nd[i]=='0')
			qzhe[i]=qzhe[i-1]+1;
		else
			qzhe[i]=qzhe[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(nd[i]=='0')
			qxhe[i]=114514;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> p[i].c;
		p[i].id=i;
	}
	sort(p+1;p+n+1,cmp);
	
	
	
	return 0;
}
