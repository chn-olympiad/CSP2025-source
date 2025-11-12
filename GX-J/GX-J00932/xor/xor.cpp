#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		}
		
	unordered_map<int,int>prefixCount;
	prefixCount[0]=1;
	int currentXor=0;
	long long count=0;
	for(int i=0;i<n;i++)
	{
		currentXor^=a[i];
		int target=currentXor^m;
		if(prefixCount.find(target)!=prefixCount.end())
		{
			count+=prefixCount[target];
			}
			prefixCount[currentXor]++; 
		}
		cout<<count<<endl;
	return 0;
}
