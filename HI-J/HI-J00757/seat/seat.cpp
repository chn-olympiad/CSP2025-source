#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q;
	priority_queue<int> maxHeap;
	cin>>q;
	maxHeap.push(q);
	int x=q;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>q;
		maxHeap.push(q);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(maxHeap.top()==x)
			{
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			maxHeap.pop();
		}
		i++;
		for(int j=n-1;j>=0;j--)
		{
			if(maxHeap.top()==x)
			{
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			maxHeap.pop();
		}
	}
	return 0;
} 
