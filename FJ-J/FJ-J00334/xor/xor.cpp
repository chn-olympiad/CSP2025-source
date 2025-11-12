#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int r[MAXN] = {0};
int xr[MAXN][2] = {0};
bool vis[MAXN] = {0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	
	int cnt = 0,cntz = 0,cnto = 0;
	bool f = 1;
	for(int i = 0;i < n;i++) cin>>r[i];
	
	for(int i = 0;i < n;i++)
	{
		if(r[i] == 1) cnto++;
		else if(r[i] == 0) cntz++;
		if(r[i] != 1 && r[i] != 0) f = 0;
	}
	
	if(f)
	{
		
		if(k == 1) cout<<cnto;
		else if(k == 0)
		{
			int cntt = 0;
			for(int i = 1;i < n;i++)
			if(r[i] && r[i-1]) cntt++,i++;
			cout<<cntz+cntt;
		}
		return 0;
	}
	
	for(int i = 0;i < n;i++)
	{
		xr[i][0] = r[i];
		if(xr[i][0] == k)
		{
			cnt++;
			vis[i] = 1;
		}
	}
	
	for(int i = 1;i < n;i++)
	{
		//for(int j = 0;j < n;j++) cout<<xr[j][0]<<" ";
		//cout<<endl;
		int nid = 0;
		for(int j = nid;j <= nid+i && nid+i < n;j++)
		if(vis[j]) nid = j+1;
		
		while(nid+i < n)
		{
			xr[nid][1] = xr[nid][0] ^ r[nid+i];
			if(xr[nid][1] == k)
			{
				cnt++;
				for(int j = nid;j <= nid+i;j++) vis[j] = 1;
			}
			nid++;
			for(int j = nid;j <= nid+i && nid+i < n;j++)
			{
				if(vis[j]) nid = j+1;
			}
		}
		
		for(int j = 0;j < n;j++) xr[j][0] = xr[j][1],xr[j][1] = 0;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
