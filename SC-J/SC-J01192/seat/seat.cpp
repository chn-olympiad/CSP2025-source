#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int N,M,A[105],R,tot;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>N>>M;
	for(int i=1;i<=N*M;i++)
	{
		cin>>A[i];
	}
	R=A[1];
	sort(A+1,A+N*M+1,cmp);
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			tot++;
			if(i%2==1)
			{
				if(A[tot]==R)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
			else
			{
				if(A[tot]==R)
				{
					cout<<i<<" "<<N-j+1<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}