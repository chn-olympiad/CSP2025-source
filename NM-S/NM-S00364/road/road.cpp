#include<bits/stdc++.h>

using namespace std;

int f[10021],n,m,k,cnt_f[10021],c[11],c_road[11][10001];
long long ans=0;
bool state=1;

struct node{
	int place1;
	int place2;
	long long value;
}d[1000001];



int find(int a)
{
	if(f[a]==a)	return a;
	return a=find(f[a]);
}

bool check_s(int a,int b)
{
	int num1=find(a);
	int num2=find(b);

	if(num1==num2)
		return 1;

	return 0;
}

void uni(int a,int b)
{
	int num1=find(a);
	int num2=find(b);

	if(cnt_f[num1]>=cnt_f[num2])
	{
		f[num2]=num1;
		cnt_f[num1] += cnt_f[num2];
	}
	else
	{
		f[num1]=num2;
		cnt_f[num2] += cnt_f[num1];
	}
}

bool cmp(node a,node b)
{
	return a.value<b.value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);


	memset(cnt_f,1,sizeof(cnt_f));
	cin >> n >> m >> k;

	for(int i=1;i<=n+k+1;i++)
		f[i]=i;

	for(int i=1;i<=m;i++)
	{
		cin >> d[i].place1 >> d[i].place2 >> d[i].value;
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> c_road[i][j];
			if(c_road[i][j]!=0)
			{
				state=0;
			}
		}
		if(c[i]!=0)
		{
			state=0;
		}
	}
	if(k&&state)
	{
		cout << 0;
	}


	if(!k)
	{
		sort(d,d+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(check_s(d[i].place1,d[i].place2))
			{
				continue;
			}
			uni(d[i].place1,d[i].place2);
			ans+=d[i].value;
		}
		cout << ans;
	}
	return 0;
}
