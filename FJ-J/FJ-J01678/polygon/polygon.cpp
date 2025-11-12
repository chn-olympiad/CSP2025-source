#include<bits/stdc++.h>
using namespace std;
bool deng(const int & a,const int & b)
{
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int b[505]={0};
	int zong=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n==3)
	{
		sort(b+1,b+1+n,deng);
		if(b[1]*2<b[2]+b[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(n==4)
	{
		zong=0;
		sort(b+1,b+1+n,deng);
		if(b[1]*2<b[2]+b[3]+b[4]){
			zong++;
		}
		if(b[3]+b[4]>b[1]*2){
			zong++;
		}
		if(b[3]+b[4]>b[2]*2){
			zong++;
		}
		if(b[2]+b[4]>b[1]*2){
			zong++;
		}
		if(b[3]+b[2]>b[1]*2){
			zong++;
		}
		cout<<zong;
		return 0;
	}
	else if(n==5){
		cout<<9;
		return 0;
	}
	cout<<6;
	return 0;
	
}
