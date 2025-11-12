#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,s,t;
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,px);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			s=i;
			break;
		}
	}
	k=s/n;
	s-=n*k;
	if(k%2==0){
		if(s==0) cout<<k<<" "<<1;
		else cout<<k+1<<" "<<s;
	}else{
		if(s==0) cout<<k<<" "<<n;
		else cout<<k+1<<" "<<n-s+1;
	}
	return 0;
}

