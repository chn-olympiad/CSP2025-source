#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
struct Node{
	int v,id;
} xorv[N];

bool cmp(Node a,Node b)
{
	return a.v<b.v;
}



int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,now;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&now);
		xorv[i].v=xorv[i-1].v xor now;
		xorv[i].id=i;
	}
	sort(xorv,xorv+n+1,cmp);
	if(k==0)
	{
		cout<<n<<endl;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int f=xorv[i].v xor k;
		f++,f--;
	}
	
	return 0;
}
