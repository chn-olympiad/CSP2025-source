#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt;//ans lie cnt hang
struct node{
	int num,r;
}a[200];
bool cmp(node c,node d){
	return c.num>d.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].num;
	a[1].r=1;
	sort(a+1,a+1+n*m,cmp);
	int b;
	for(int i=1;i<=n*m;i++)
		if(a[i].r){
			b=i;
			break;
		}
	ans=b/n+1;
	if(b%n==0){
		ans--;
		cout<<ans<<" ";
		if(ans%2)
			cout<<n;
		else cout<<1;
		return 0;
	}
	b=b-b/n*n;
	if((ans-1)%2==0)
		cnt=b;
	else cnt=n+1-b;
	cout<<ans<<" "<<cnt;
	return 0;
}
