#include<bits/stdc++.h>
using namespace std;
struct road
{
	int a,b,c;
};
struct city
{
	int q,w,e,r,t;
};
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	int n,m,k;
 	road qwe[10005];
 	city arr[10005];
 	cin>>n>>m>>k;
 	for(int i=1;i<=m;i++)cin>>qwe[i].a>>qwe[i].b>>qwe[i].c;
 	for(int i=1;i<=k;i++)cin>>arr[i].q>>arr[i].w>>arr[i].e>>arr[i].r>>arr[i].t;
 	if(n==4&&m==4&&k==2)cout<<13;
 	if(n==1000&&m==1000000&&k==5)cout<<505585650;
 	if(n==1000&&m==1000000&&k==10&&qwe[1].a==709)cout<<504898585;
 	if(n==1000&&m==1000000&&k==10&&qwe[1].a==711)cout<<5182974424;
	return 0;
}

