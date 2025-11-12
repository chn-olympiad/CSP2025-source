#include<bits/stdc++.h>
using namespace std;
int n,m;
int flag1;
struct node{
	int val;
	bool flag;
}a[110];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		if(i==1) a[i].flag=1;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].flag==1){
			flag1=i;
			break;
		}
	}
	int cnt=0;
	while((flag1+cnt)%n!=0) cnt++;
	int ans=(flag1+cnt)/n;
	cout<<ans<<" ";
	if(ans%2==0) cout<<1+cnt;
	else if(ans%2==1) cout<<n-cnt;
	return 0;
}