#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[110];
bool b=1,c=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	sum=a[1];
	sort(a+1,a+n*m+1);
	long long x=1,y=0;
	for(int i=n*m;i>=1;i--){
		if((x==n || x==1) && c==0)y++,b=(b?0:1),c=1;
		else if(b==false)x++,c=0;
		else x--,c=0;
		if(a[i]==sum){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
} 
