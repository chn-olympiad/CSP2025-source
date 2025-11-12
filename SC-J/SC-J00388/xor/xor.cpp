#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500001],ans;
void dfs(int front,int rear,int number)
{
	if(front>rear||front>n||rear>n)
	{
		ans= max(number,ans);
		return;
		}    
	int cnt=a[front];
	for(int i=front+1;i<=rear;i++)
	    cnt=cnt^a[i];
	if(cnt==k)
	    dfs(rear+1,rear+1,number+1);
	else{
		dfs(front,rear+1,number);
		dfs(front+1,rear,number);
	} 
	
 } 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	dfs(1,1,0);
	cout<<ans; 
	return 0;
}