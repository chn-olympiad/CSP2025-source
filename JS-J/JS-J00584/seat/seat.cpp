#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,p,score;
	cin>>n>>m;
	vector<int> arr(n*m);
	for(int i=0;i<n*m;i++)
		cin>>arr[i];
	score=arr[0];
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n*m;i++)
	{
		if(arr[i]==score)
		{
			p=i;
			break;
		}
	}
	int a=p/n+1,b=p%n+1;
	if(a%2==0)
	{
		cout<<a<<' '<<n+1-b;
	}
	else
	{
		cout<<a<<' '<<b;
	}
	return 0;
}
