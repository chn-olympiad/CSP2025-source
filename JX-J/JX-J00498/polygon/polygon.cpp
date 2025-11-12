#include<bits/stdc++.h>
using namespace std;
int a,b[5005],d[5005],an;
bool c[5005];
int qwe(int x,int x1)
{
	int ans=0;
	if(x==0){
		int y=0,z=0;
		for(int i=1;i<d[0];i++){
			y+=d[i];
			if(z<d[i]) z=d[i];
		}
		if(y>z*2) return 1;
		return 0;
	}
	for(int i=x1;i<a;i++){
		if(a-i<x) break;
		if(c[i]) continue;
		c[i]=1;
		d[d[0]]=b[i];
		d[0]++;
		ans+=qwe(x-1,x1+1);
		c[i]=0;
		d[0]--;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int i=3;i<=a;i++){
		d[0]=1;
		an+=qwe(i,0);
	}
	cout<<an%998%244%353;
	return 0;
}
