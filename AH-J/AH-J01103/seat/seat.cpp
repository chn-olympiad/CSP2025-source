#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],mc,fs;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	fs=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==fs)mc=i;
	}
	int c,r;
	if(mc%n==0) c=mc/n;
	else c=mc/n+1;
	if(c%2==1&&mc%n!=0) r=mc%n;
	else if(c%2==1&&mc%n==0) r=n;
	if(c%2==0&&mc%n!=0) r=n-mc%n+1;
	else if(c%2==0&&mc%n==0) r=1;
	cout<<c<<' '<<r;
	return 0;
}
