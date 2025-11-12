#include<bits/stdc++.h>
using namespace std;
//T3 : 50 pts

const int N = 5e5+10;
int a[N],x[N];

struct node{
	int l,r;
};

vector<node> v;

bool cmp(node t1,node t2)
{
	return t1.r < t2.r;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	x[1] = a[1];
	for(int i=2;i<=n;i++)
	{
		x[i] = (x[i-1] ^ a[i]);
	}
	
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i;j<=n;j++)
		{
			//[i,j]
			if((x[j] ^ x[i-1]) == k)
			{
				v.push_back({i,j}); 
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	
	int len = v.size();
	
	sort(v.begin(),v.end(),cmp);
	
	
	int ed = v[0].r,cnt = 1;
	for(int i=1;i<len;i++)
	{
		if(v[i].l > ed)
		{
			cnt ++;
			ed = v[i].r;
		}
	}
	
	cout<<cnt;
	
	
	return 0;
}
/*
4 3
2 1 0 3

*/