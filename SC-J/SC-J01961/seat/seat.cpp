#include<bits/stdc++.h> 
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int l=n*m;
	for(int i=1;i<=l;i++)
		scanf("%d",&a[i]);
	int cnt=a[1],ans;
	sort(a+1,a+l+1);
	for(int i=1;i<=l;i++)
		if(a[i]==cnt) ans=i;
	ans=l-ans+1;
	int y=ans%n,x=ans/n;
	if(y!=0) x++;
	if(y==0) y=n;
	if(x&1) cout<<x<<" "<<y;
	else cout<<x<<" "<<n+1-y;
	return 0;
}