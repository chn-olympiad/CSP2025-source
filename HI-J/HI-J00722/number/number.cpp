#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	vector<string> a={1000,0};
	int pos=0;
	for(int i=1;i<=10000;i++)
	{
		cin>>a[i];
		pos++;
	}
	a[pos+2]=-1;
	int k[10]={0};
	int temp=0;
	for(int i=1;i<=pos;i++)
	{
		int temp=a[i];
		k[temp]++;
	}
	
	for(int i=9;i>=0;i--)
	{
		if(k[i]!=0)
		{
			for(int j=1;j<=k[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
	
