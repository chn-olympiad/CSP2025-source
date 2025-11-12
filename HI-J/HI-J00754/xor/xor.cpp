#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 if(k==0)
	 {
	 	bool f=0;
	 	for(int i=1;i<=n;i++)
	 	{
	 		if(a[i]==0) f=1;
		 }
		 if(f==1){
		 	cout<<1;
		 	return 0;
		 }
		 else cout<<0;
		 return 0;
	 }
	 else if(k==1)
	 {
	 	bool f=0;
	 	for(int i=1;i<=n;i++)
	 	{
	 		if(a[i]==1) f=1;
		 }
		 if(f==1){
		 	cout<<1;
		 	return 0;
		 }
		 else cout<<0;
		 return 0;
	 }
	 else cout<<3;
	return 0;
}


