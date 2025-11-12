#include<bits/stdc++.h>
using namespace std;
int tong[10000000];
int cnt[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	int len=x.length();
	char a;
	
	for(int i=0;i<len;i++)
	{
		a=x[i];
		if(48<=int(a)<=57) 
		{
			tong[int(a)-48]=1;
			cnt[int(a)-48]++;
		}
	}
	int cnt2;
	for(int i=10;i>=0;i--)
	{
		if(tong[i]==1)
		{
			cnt2=cnt[i];
			while(cnt2!=0)
			{
				cout<<i;
				cnt2--;
			}
		}
	}
}
