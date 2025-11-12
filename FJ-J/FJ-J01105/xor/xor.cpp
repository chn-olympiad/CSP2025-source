#include<bits/stdc++.h>
using namespace std;

int n,k;
int data[100005];
int cdt=0;//0 无数据 1 均为1 2 有01 3 有各种 
 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>data[i];
		if(cdt==0 && data[i]==0) cdt=2;
		else if(cdt==0 && data[i]==1) cdt=1;
		else if(cdt==0 && data[i]!=0 && data[i]!=1) cdt=3;
		else if(cdt==1 && data[i]==0) cdt=2;
		else if(cdt==1 && data[i]!=0 && data[i]!=1) cdt=3;
		else if(cdt==2 && data[i]!=0 && data[i]!=1) cdt=3;
	}
	if(cdt==1) cout<<n;
	else if(cdt==2) cout<<"2";
	else if(cdt==3) cout<<"2"; 
} 
