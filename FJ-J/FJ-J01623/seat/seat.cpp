#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n,m;
struct node{
	int id; 
	int fen;
}a[N];
bool cmp(node x,node y){
	return x.fen>y.fen;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i].fen;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			int l=(i+n-1)/n;
			cout<<l<<" ";
			int h;
			if(i%n==0) h=n;
			else h=i%n;
			if(l%2) cout<<h;
			else cout<<n-h+1;
		}
	}
	return 0;
}
