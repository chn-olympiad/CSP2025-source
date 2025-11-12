#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,ans,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if (n==1){
		cout<<0<<endl;
		return 0;
	}
	if (n==2 && k==0)
	{
		cout<<1<<endl;
		return 0;
	}
	
	int num1=0,num2=0,num3=0;
	if (k==0){
		for (int i=1;i<=n;i++){
			if (a[i]==0) num1++;
		}
		for (int i=1;i<n;i++){
			if (a[i]==a[i+1]){
				num2++;
				i++;
			}
		}
		for (int i=1;i<=n;i++){
			if (a[i]==a[i+1] && a[i+1]==a[i+2] && a[i]==0){
				num3++;
				i+=2;
			}
			if (a[i]==a[i+1] && a[i]==1 && a[i+2]==0)
			{
				num3++;
				i+=2;
			}
			if (a[i]==a[i+2] && a[i]==1 && a[i+1]==0){
				num3++;
				i+=2;
			}
			if (a[i+1]==a[i+2] && a[i+1]==1 && a[i==0]){
				num3++;
				i+=2;
			}
		}
		ans=max(num1,max(num2,num3));
		cout<<ans<<endl;
	}
	if (k==1){
		for (int i=1;i<=n;i++){
			if (a[i]==1) num1++;
		}
		for (int i=1;i<n;i++){
			if (a[i]!=a[i+1]){
				num2++;
				i++;
			}
		}
		for (int i=1;i<=n;i++){
			if (a[i]==a[i+1] && a[i+1]==a[i+2] && a[i]==1){
				num3++;
				i+=2;
			}
			if (a[i]==a[i+2] && a[i]==0 && a[i+1]==1){
				num3++;
				i+=2;
			}
			if (a[i]==a[i+1] && a[i]==0 && a[i+2]==1){
				num3++;
				i+=2;
			}
			if (a[i+1]==a[i+2] && a[i+1]==0 && a[i]==1)
			{
				num3++;
				i+=2;
			}
		}
		ans=max(num1,max(num2,num3));
		cout<<ans<<endl;
	}
	return 0;
}
