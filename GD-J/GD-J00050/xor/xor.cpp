#include<bits/stdc++.h>
using namespace std;

int  a[500005];
int d[1000010];
int n,k;
vector<pair<int,int> > found;

bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(x.second-x.first<y.second-y.first)
		return 1;
	else
		return 0;
}

void build(int s,int t,int p)
{
	if(s==t)
	{
		d[p]=a[s];
		return;
	}
	int m = s+((t-s)>>1);
	//cerr<<m<<endl;
	build(s,m,p*2),build(m+1,t,p*2+1);
	d[p] = d[p*2] xor d[p*2+1];
}
// [l,r]为要搜寻的区间 [s,t]为当前区间 
int getxor(int l,int r,int s,int t,int p)
{
	if(l<=s&&t<=r)
	{
		return d[p];
	}
	int m = s+((t-s)>>1);
	int xor1=0,xor2=0;
	if(l<=m) xor1=getxor(l,r,s,m,p*2);
	if(r>m) xor2=getxor(l,r,m+1,t,p*2+1);
	return xor1 xor xor2;
}

void find(int s)
{
	if(s>n)
	{
		return;
	}
	for(int i=s;i<=n;i++)	//暴力查找[s,i]
	{
		if(k==getxor(s,i,1,n,1))
		{
			//cerr << "have found:["<<s<<","<<i<<"]"<<endl;
			found.push_back(make_pair(s,i));
			find(i+1);
			break;
		}
	}
	
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	build(1,n,1);
	find(1);
	//sort(found.begin(),found.end(),cmp);
	cout << found.size() << endl;
	return 0;
}
