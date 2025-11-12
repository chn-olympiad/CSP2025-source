#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
struct E{
	int l;
	int r;
}v[5000005];

int op=1; 

bool cmp(const E &a,const E &b)
{
	return a.r < b.r;
}

int main()
{
//	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i] == k)
		{
			v[op++] = {i,i};
		}
	}
	for(int i=1;i<n;i++)
	{
		if(i % 2 == 1)
		{
			for(int j=1;j<=n-i;j++)
			{
				b[j] = a[j] ^ a[j+1];
				if(b[j] == k)
				{
					v[op++] = {j,i+j};
//					cout<<"check";
				}
				
//				cout<<b[j]<<' ';
			}
		}
		else
		{
			for(int j=1;j<=n-i;j++)
			{
				a[j] = b[j] ^ b[j+1];
				if(a[j] == k)
				{
					v[op++] = {j,i+j};
//					cout<<"check";
				}
				
//				cout<<a[j]<<' ';
			}
		}
		
//		cout<<endl;
	}
//	for(int i=1;i<op;i++)
//	{
//		cout<<v[i].r<<' ';
//	}
	
	sort(v+1,v+op,cmp);
	
//	for(int i=1;i<op;i++)
//	{
//		cout<<v[i].l<<' '<<v[i].r<<' ';
//	}
//	cout<<endl;
	
	int ans=0;
	if(op!=1)ans++;
	int ll = v[1].l,rr = v[1].r;
	for(int i=2;i<op;i++)
	{
		if(v[i].l <= rr)continue;
		
//		cout<<"check";
		rr = v[i].r;
		ans++;
	}
	cout<<ans;
	return 0;
}
