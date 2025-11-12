#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],z,v,q;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	v=n*m;
	for(int i=1;i<=v;i++)cin>>a[i];
	z=a[1];
	sort(a+1,a+1+v,cmp);
	for(int i=1;i<=v;i++)if(a[i]==z)q=i;
	int d=q/n;
	if(n*d==q){
		cout<<d<<" ";
		cout<<n;
	} else {
		cout<<d+1<<" ";
		if(d%2==0){
			cout<<q-(n*d);
		}else cout<<n-(q-(n*d))+1;
	}
	return 0;
}
