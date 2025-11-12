#include<bits/stdc++.h>
using namespace std;
int a[1000000];
//	int tong[1000000];
//
//int judge(int a)
//{
//	int flag=9;
//	int cnt=0;
//		while(flag!=1)
//	{
//		if(pow(2,cnt)<=a&&a<pow(2,cnt+1))
//		{
//			return cnt;
//		}
//		else cnt++;
//	}
//}
//string tentotwo(int a)
//{
//
//	string x;
//	bool flag=0;
//	int len;
//	while(a!=0)
//	{
//		int num=judge(a);
//		if(flag==0)
//		{
//			 len=num;
//			 flag=1;
//		}
//		tong[num]++;
//		a-=pow(2,num);
//	}
//	for(int i=len;i>=0;i--)
//	{
//		if(tong[i]==1) x+='1';
//		else x+='0';
//	}
//	return x;
//}
//int yh(string a,string b)
//{
//    
//}
// 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n>>k;
	int sum;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n&&k==0) cout<<n/2;
	int cnt2=0;
	int cnt3=0;
	if(sum!=n&&k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0) cnt2++;
		    if(a[i]==1&&a[i+1]==1) cnt2++;
		    
		}
		cout<<cnt2;
	}
	int ans=0;
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0) continue;
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
}
