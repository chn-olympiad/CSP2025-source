#include <bits/stdc++.h>
using namespace std;
const long long N=1e2+5;
bool cmp(int a,int b)
{
	return a>b;
}
int n,m,sum[N],s,c;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>> n >> m;
	for(int i=0;i<n*m;i++) cin>>sum[i];
	s=sum[0];
	sort(sum,sum+n*m,cmp);
	for(int i=0;i<n*m;i++) if(s==sum[i]){s=i+1;break;}
	if(s%m==0){c=s/m;cout<<c<<' ';}
	else {c=s/m+1;cout<<c<<' ';}
	if(c%2==1){
		if(s%n==0) cout<<n;
	    else cout<<s%n;
	}else if(c%2==0){
		if(s%n==0) cout<<1;
		else cout<<n-s%n+1;
	}
	return 0;
} 
