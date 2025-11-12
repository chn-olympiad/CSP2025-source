#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int dq;
	cin>>dq;
	for(int i=2;i<=n*m;++i) cin>>a[i];
	a[1]=dq;
	sort(a+1,a+1+n*m,cmp);
	int ans=0;
	for(int i=1;i<=n*m;++i){
		if(a[i]==dq) ans=i;
	}
	int dqh=1,dql=1;
	for(int i=1;i<=ans-1;++i){
		if(dql%2==1){
			if(dqh==n) dql++;
			else dqh++;
		}else{
			if(dqh==1) dql++;
			else dqh--;
		}
	}
	cout<<dql<<" "<<dqh;
	return 0;
}