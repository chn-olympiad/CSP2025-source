#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int N=1e2+5;
struct st{
	int v,id;
}arr[N];
int n,m;
bool cmp(st x,st y){return x.v>y.v;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i].v;arr[i].id=i;
	}
	sort(arr+1,arr+n*m+1,cmp);
	int k;
	for(int i=1;i<=n*m;i++)
		if(arr[i].id==1){k=i;break;}/*
	for(int i=1;i<=n*m;i++)
		cerr<<arr[i].v<<" "<<arr[i].id<<"\n";
	cerr<<k<<"\n";*/
	int x,y;
	if(k%n==0)
		x=k/n;
	else
		x=k/n+1;
	if(x%2==1)
		y=(k%n==0)?n:k%n;
	else
		y=n-(k%n)+1;
	
	cout<<x<<" "<<y<<"\n";
	return 0;
} 
