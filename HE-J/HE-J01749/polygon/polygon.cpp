#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poplygon.in","r",stdin);
	freopen("poplygon.out","w",stdout);
	int n;
	cin>>n;
	int a[1000];
	int num=0;
	int l=0;
	int o=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]+a[i+1]>a[i+2])
		{
			num++;
		}
		if(a[i]+a[i+1]+a[i+2]>a[i+3])
		{
			l++;
		}
		if(a[i]+a[i+1]+a[i+2]+a[i+3]>a[i+4])
		{
			o++;
		}
	}
	cout<<num+l+o+3;
	frclose(stdin);
	frclose(stdout);
	return 0;
}
