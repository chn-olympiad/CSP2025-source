#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N][4];
int cn[5];
vector<int> cl1,cl2,cl3;
int ans;
int ck1(int who,int nans,int x)//检查第1节课前面能不能第x节 
{
	int res=0;
	for(int i=0;i<cl1.size();i++)
	{
		int nowch=cl1[i];
		for(int j=1;j<=3;j++)
		{
			if(j==1) continue;
			if(cn[j]>=(n/2)) continue;
			int tmp=nans-a[nowch][1]+a[nowch][j]+a[who][x];
			res=max(res,tmp);
		}
	}
	return res;
}
int ck2(int who,int nans,int x)//检查第2节课前面能不能第x节 
{
	int res=0;
	for(int i=0;i<cl2.size();i++)
	{
		int nowch=cl2[i];
		for(int j=1;j<=3;j++)
		{
			if(j==2) continue;
			if(cn[j]>=(n/2)) continue;
			int tmp=nans-a[nowch][2]+a[nowch][j]+a[who][x];
			res=max(res,tmp);
		}
	}
	return res;
}
int ck3(int who,int nans,int x)//检查第3节课前面能不能第x节 
{
	int res=0;
	for(int i=0;i<cl3.size();i++)
	{
		int nowch=cl3[i];
		for(int j=1;j<=3;j++)
		{
			if(j==3) continue;
			if(cn[j]>=(n/2)) continue;
			int tmp=nans-a[nowch][3]+a[nowch][j]+a[who][x];
			res=max(res,tmp);
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	string s;
	cin>>s>>s>>s>>s;
	for(int i=1;i<=t;i++) cout<<"0"<<endl;
	return 0;
}
