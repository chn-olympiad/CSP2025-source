#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int m,n,x,y;
int a[N];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+sum,cmp);
	int num;
	for(num=1;num<=sum;num++) if(a[num]==t) break;
	x=num/n;
	if(num%n) x++;
	num=(num-1)%n+1;
	if(x%2) y=num;
	else y=n-num+1;
	cout<<x<<" "<<y;
	return 0;
}