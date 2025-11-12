#include<bits/stdc++.h>
//#define int long long
using namespace std;
const  int maxn=1e3+10;
int n,m;
int na,ma;
struct node{
	int num;
	int p;
};
node a[maxn];
int q;
int b;
bool cmp(node a,node b){
	return a.num>b.num;
}
int  main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].p=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].p==1) 
		{
			b=i;
			break;
		}
	}
//	cout<<b<<" ";
	ma=(b+n-1)/n;
	if(ma%2==0)
	{
		na=n-(b-(ma-1)*n)+1;
	}else
	{
		na=b-(ma-1)*n;
	}
	cout<<ma<<" "<<na;
	return 0;
}

