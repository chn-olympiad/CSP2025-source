#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,r,a[200],r_id;
bool cmp(int x,int y){	
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=(m*n);i++)cin>>a[i];
	r=a[1];sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=(m*n);i++)if(a[i]==r){r_id=i;break;}
	int m1=r_id/n,n1=r_id%n;
	if(n1==0){
		cout<<m1<<" ";
		if(m1%2==1)cout<<n;
		else cout<<1;
		
	}
	else{
		m1++;
		cout<<m1<<" ";
		if(m1%2==1)cout<<n1;
		else cout<<n-n1+1;
	}
	return 0;
}