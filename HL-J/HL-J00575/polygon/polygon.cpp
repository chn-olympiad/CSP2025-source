#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		long long maxx=max(a[1],max(a[2],a[3]));
		long long sum=a[1]+a[2]+a[3];
		if(2*maxx<sum){
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(n==4)
	{
		long long cnt=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4])))cnt++;
		if(a[1]+a[4]+a[3]>2*max(a[1],max(a[4],a[3])))cnt++;
		if(a[3]+a[2]+a[4]>2*max(a[3],max(a[2],a[4])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))cnt++;
		cout<<cnt<<endl;
		return 0;
	}
	if(n==5)
	{
		long long cnt=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4])))cnt++;
		if(a[1]+a[4]+a[3]>2*max(a[1],max(a[4],a[3])))cnt++;
		if(a[3]+a[2]+a[4]>2*max(a[3],max(a[2],a[4])))cnt++;
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5])))cnt++;
		if(a[1]+a[5]+a[4]>2*max(a[1],max(a[5],a[4])))cnt++;
		if(a[5]+a[4]+a[3]>2*max(a[5],max(a[4],a[3])))cnt++;
		if(a[3]+a[2]+a[5]>2*max(a[3],max(a[2],a[5])))cnt++;
		if(a[3]+a[1]+a[5]>2*max(a[3],max(a[1],a[5])))cnt++;
		if(a[4]+a[2]+a[5]>2*max(a[4],max(a[2],a[5])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))cnt++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(max(a[1],a[2]),max(a[3],a[5])))cnt++;
		if(a[5]+a[2]+a[1]+a[4]>2*max(max(a[5],a[2]),max(a[1],a[4])))cnt++;
		if(a[5]+a[1]+a[3]+a[4]>2*max(max(a[5],a[1]),max(a[3],a[4])))cnt++;
		if(a[5]+a[2]+a[3]+a[4]>2*max(max(a[5],a[2]),max(a[3],a[4])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(max(a[1],a[2]),max(max(a[3],a[4]),a[5])))cnt++;
		cout<<cnt<<endl;
		return 0;
	}
	if(n==6)
	{
		long long cnt=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4])))cnt++;
		if(a[1]+a[4]+a[3]>2*max(a[1],max(a[4],a[3])))cnt++;
		if(a[3]+a[2]+a[4]>2*max(a[3],max(a[2],a[4])))cnt++;
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5])))cnt++;
		if(a[1]+a[5]+a[4]>2*max(a[1],max(a[5],a[4])))cnt++;
		if(a[5]+a[4]+a[3]>2*max(a[5],max(a[4],a[3])))cnt++;
		if(a[3]+a[2]+a[5]>2*max(a[3],max(a[2],a[5])))cnt++;
		if(a[3]+a[1]+a[5]>2*max(a[3],max(a[1],a[5])))cnt++;
		if(a[4]+a[2]+a[5]>2*max(a[4],max(a[2],a[5])))cnt++;
		if(a[1]+a[5]+a[6]>2*max(a[1],max(a[5],a[6])))cnt++;
		if(a[1]+a[2]+a[6]>2*max(a[1],max(a[2],a[6])))cnt++;
		if(a[1]+a[3]+a[6]>2*max(a[1],max(a[3],a[6])))cnt++;
		if(a[1]+a[4]+a[6]>2*max(a[1],max(a[4],a[6])))cnt++;
		if(a[1]+a[5]+a[6]>2*max(a[1],max(a[5],a[6])))cnt++;
		if(a[2]+a[3]+a[6]>2*max(a[2],max(a[3],a[6])))cnt++;
		if(a[2]+a[4]+a[6]>2*max(a[2],max(a[4],a[6])))cnt++;
		if(a[2]+a[5]+a[6]>2*max(a[2],max(a[5],a[6])))cnt++;
		if(a[3]+a[4]+a[6]>2*max(a[3],max(a[4],a[6])))cnt++;
		if(a[3]+a[5]+a[6]>2*max(a[3],max(a[5],a[6])))cnt++;
		if(a[4]+a[5]+a[6]>2*max(a[4],max(a[5],a[6])))cnt++;
		if(a[1]+a[2]+a[3]+a[6]>2*max(max(a[1],a[2]),max(a[3],a[6])))cnt++;
		if(a[1]+a[2]+a[4]+a[6]>2*max(max(a[1],a[2]),max(a[4],a[6])))cnt++;
		if(a[1]+a[2]+a[5]+a[6]>2*max(max(a[1],a[2]),max(a[5],a[6])))cnt++;
		if(a[1]+a[3]+a[4]+a[6]>2*max(max(a[1],a[3]),max(a[4],a[6])))cnt++;
		if(a[1]+a[3]+a[5]+a[6]>2*max(max(a[1],a[3]),max(a[5],a[6])))cnt++;
		if(a[1]+a[4]+a[5]+a[6]>2*max(max(a[1],a[4]),max(a[5],a[6])))cnt++;
		if(a[2]+a[3]+a[5]+a[6]>2*max(max(a[2],a[3]),max(a[5],a[6])))cnt++;
		if(a[2]+a[4]+a[5]+a[6]>2*max(max(a[2],a[4]),max(a[5],a[6])))cnt++;
		if(a[3]+a[4]+a[5]+a[6]>2*max(max(a[3],a[4]),max(a[5],a[6])))cnt++;
		//if(a[]+a[]+a[]+a[]>2*max(max(a[],a[]),max(a[],a[])))cnt++;
		//if(a[]+a[]+a[]+a[]>2*max(max(a[],a[]),max(a[],a[])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))cnt++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(max(a[1],a[2]),max(a[3],a[5])))cnt++;
		if(a[5]+a[2]+a[1]+a[4]>2*max(max(a[5],a[2]),max(a[1],a[4])))cnt++;
		if(a[5]+a[1]+a[3]+a[4]>2*max(max(a[5],a[1]),max(a[3],a[4])))cnt++;
		if(a[5]+a[2]+a[3]+a[4]>2*max(max(a[5],a[2]),max(a[3],a[4])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(max(a[1],a[2]),max(max(a[3],a[4]),a[5])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>2*max(max(a[1],a[2]),max(max(a[3],a[4]),a[6])))cnt++;
		if(a[1]+a[2]+a[3]+a[5]+a[6]>2*max(max(a[1],a[2]),max(max(a[3],a[5]),a[6])))cnt++;
		if(a[1]+a[2]+a[4]+a[5]+a[6]>2*max(max(a[1],a[2]),max(max(a[4],a[5]),a[6])))cnt++;
		if(a[1]+a[3]+a[4]+a[5]+a[6]>2*max(max(a[1],a[3]),max(max(a[4],a[5]),a[6])))cnt++;
		if(a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(a[2],a[3]),max(max(a[4],a[5]),a[6])))cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(a[1],a[2]),max(max(a[3],a[4]),max(a[5],a[6]))))cnt++;
		//if(a[]+a[]+a[]+a[]+a[]>2*max(max(a[],a[]),max(max(a[],a[]),a[])))cnt++;
		//if(a[]+a[]+a[]+a[]+a[]>2*max(max(a[],a[]),max(max(a[],a[]),a[])))cnt++;
		//if(a[]+a[]+a[]+a[]+a[]>2*max(max(a[],a[]),max(max(a[],a[]),a[])))cnt++;
		//if(a[]+a[]+a[]+a[]+a[]>2*max(max(a[],a[]),max(max(a[],a[]),a[])))cnt++;
		cout<<cnt<<endl;
		return 0;
	}
	else cout<<0x3f3f3f;
	return 0;	
}  
