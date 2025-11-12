#include<iostream>
#include<iomanip>
#include<algorithm> 
#include<vector>
using namespace std;
struct L{
	int u,v,w;
};
struct G{
	int c;
	int v[100001];
};
bool cmp(L a,L b)
{
	return a.w < b.w;
}
bool tmp(G a,G b)
{
	return a.c < b.c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	
	int n,m,k,ans=0;
	cin >> n >> m >> k ;
	vector<L> arr(m+1);
	vector<G> brr(k+1);
	vector<vector<int>> num(n+1);
	for(int i=1;i<=m;++i) cin >> arr[i].u >> arr[i].v >> arr[i].w;
	for(int i=1;i<=k;++i) 
	{
		cin >> brr[i].c;
		for(int j=1;j<=n;++j) cin>>brr[i].v[j];
	}
	sort(arr.begin(),arr.end(),cmp);
	//sort(brr.begin(),brr.end(),tmp);
	for(int i=1;i<=n-2;++i)
	{
		ans += arr[i].w;
		num[arr[i].u].push_back(arr[i].v);
		num[arr[i].v].push_back(arr[i].u);
	}
	//cout << ans << "\n"; 
	for(int i=1;i<=n;++i)
	{
		if(!(num[i].size()))
		{
			int a1 = brr[1].c,ti = 1;
			for(int j = 2;j <= k; ++ j)
			{
				if(a1 > brr[j].c)
				{
					a1 = brr[j].c , ti = j;
				}
			}		
			ans += a1;
			sort(brr[ti].v+1,brr[ti].v+n+1);
			ans += brr[ti].v[1] + brr[ti].v[2];
		}
 
	}
	cout << ans << "\n";
	/*for(int i=1;i<=n;i++)
	{
		for(auto & x : num[i]) cout << x << " ";
		cout << "\n";
	}
	*/
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
