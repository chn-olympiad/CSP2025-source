#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
void A(int n,int r){
	int dep=1,s[5005];
	bool vis[5005];
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			s[dep]=a[i];
			dep++;
			vis[i]=true;
		}
		if(dep>r)
		{
			int sum=0,Max=-1;
			for(int j=1;j<=r;j++)
			{
//				cout<<"side:"<<s[j]<<" ";
				Max=max(Max,s[j]);
				sum+=s[j];
			}
			if(sum>=2*Max)ans++;
			dep--;
		}
	}

//	cout<<"\n";
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)
	{
//		cout<<"sidenum:"<<i<<"\n";
		A(n,i);
	} 
	cout<<ans;
		
	return 0;
}
/*
5
1 2 3 4 5
*/
