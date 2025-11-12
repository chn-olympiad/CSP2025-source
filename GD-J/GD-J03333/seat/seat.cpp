#include<bits/stdc++.h>
using namespace std;
int n,m,f;
struct node{
	int num,rank;	
}a[105];
bool cmp(node x,node y){
	return x.num>y.num;
}
int Find(int x){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i].rank==1)return cnt;
		else cnt++;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].num,a[i].rank=i;
	sort(a+1,a+1+n*m,cmp);
	int k=Find(1)+1;
	if(k%n==0)f=k/n;
	else f=k/n+1;
	cout<<f<<" ";
	int p=k%n;
	if(f==1)cout<<k;
	else if(f%2==0)cout<<n-p+1;
	else if(f%2==1)cout<<p;
	return 0;
}
