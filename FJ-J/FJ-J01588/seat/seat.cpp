#include<bits/stdc++.h>
#define ifo(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
int n,m,a[105],a1,a2,ans;
bool cmp(int a1,int b1){
	return a1>b1;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(),cout.tie();
	cin>>n>>m;
	ifo(i,1,n*m)cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	ifo(i,1,n*m){
		if(a1==a[i]){
			a1=i;
			break;
		}
	}
	a2=(a1-1)%n;
	a1=(a1%n==0)?(a1/n):(a1/n+1);
	cout<<a1<<' ';
	if(a1%2==0)cout<<n-a2;
	else cout<<a2+1;
	return 0;
} 
