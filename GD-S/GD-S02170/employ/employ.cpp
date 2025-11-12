#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;//分别表示参与人数和目标招聘人数 
string a;
string nd[N];//表示每一天分别的难度 
int nai[N]; 
bool byi=true;//ALL OF ONE
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int nn=n;
	for(int i=0;i<nn;i++)
	{
		cin>>nai[i];
		if(nai[i]==0)
		{
			 i--;
			 nn--;
		 }
	}
		for(int i=0;i<n;i++)
	{
		string q=a.substr(0,1);
			a.erase(0,1);
		nd[i]=q;
		if(nd[i]=="0") byi=false;
	}
	if(byi)
	{
		if(nn>=m)
		{
				int sum=1;
		while(nn)
		{
			sum*=nn;
			nn--;
		}
		cout<<sum;
		return 0;
		}
	cout<<"0";
	return 0;
	}
	return 0;
}
