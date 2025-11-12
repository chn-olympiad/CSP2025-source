#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105]={},mine,now;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i];
	mine=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	  if(a[i]==mine)
	    now=i;
	if(now%(2*n)==0)
	  cout<<now/(2*n)*2<<" "<<1;
	else if(now%n==0)
	  cout<<now/n<<" "<<n;
	else
	  if(now%(2*n)<n)
		cout<<now/(2*n)*2+1<<" "<<now%n;
	  else
		cout<<now/(2*n)*2+2<<" "<<n+1-now%n;
	return 0;
}
