#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int seat;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=m*n;
	cin>>seat;
	a[1]=seat;
	for(int i=2;i<=x;i++){
		cin>>a[i];
	}
	sort(a+1,a+x+1,cmp);
	int cnt=1;
	while(a[cnt]!=seat){
		cnt++;
	}
	int ans=(cnt-1)/n;
	ans++;
	int temp=0;
	if(ans%2){
		temp=cnt%n;
		if(temp==0) temp=n;
	}else{
		temp=n-cnt%n+1;
		if(cnt%n==0) temp=1;
	}
	cout<<ans<<" "<<temp;
	return 0;
}
