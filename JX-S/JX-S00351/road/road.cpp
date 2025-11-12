#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int total=0;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
	}
	for(int yy=2;yy<=n;yy++){
		int nowmoney=1000000;
		for(int i=1;i<=m;i++){
			if(a[i]==(yy-1)&&b[i]==yy){
				if(c[i]<nowmoney)nowmoney=c[i];
			}
			if(a[i]==yy&&b[i]==(yy-1)){
				if(c[i]<nowmoney)nowmoney=c[i];
			}
		}
		total+=nowmoney;
	}
	
	cout<<total;
		
	return 0;
}
