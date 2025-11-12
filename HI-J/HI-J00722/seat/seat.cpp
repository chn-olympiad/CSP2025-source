#include<bits/stdc++.h>
#define ll long long
using namespace std;
int paixv(vector<int>& arr)
{
	int a[101]={0};
	int n=arr.size();
	for(int i=1;i<=n;i++)
	{
		a[arr[i]]++;
	}
	int xvlie[n+1];
	int pos=1;
	for(int i=100;i<=1;i--)
	{
		for(int j=1;j<=a[i];j++)
			xvlie[j]=a[i];
	}
	return 0;
}
int main(){
	int n,m;
	cin>>n>>m;
	int n1=n*m;
	vector<int> chengji;
	for(int i=1;i<=n1;i++)
	{
		cin>>chengji[i];
	}
	int temp=chengji[1];
	paixv(chengji);
	int posa=1;
	for(int i=1;i<=n;i++)
	{
		if(temp==chengji[i])
			break;
		posa++;
	}
	int x=posa/n;
	int y;     
	if(x%2==0)
	{
		y=n-posa%n+1;
	}
	else
	{
		y=posa%n;
	}
	cout<<x<<y;
	return 0;
}
