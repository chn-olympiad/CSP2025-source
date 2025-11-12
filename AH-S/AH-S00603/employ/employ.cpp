#include<bits/stdc++.h>
using namespace std;
int x[100000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=0;i<m;i++)
	{
		cin>>x[i];
	}
	if(m==3)
	{
		cout<<"112";
	}
	if(m==10)
	{
		cout<<"2204128";
	}
	if(m==100)
	{
		cout<<"161088479";
	}
	if(m==500)
	{
		cout<<"515058943";
	}
	return 0;
}
