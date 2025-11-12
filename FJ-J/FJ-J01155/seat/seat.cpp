#include<bits/stdc++.h>
using namespace std;
int a[1001001];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(cnt==a[i]){
			cnt=i;
			break;
		}
	}if(((cnt-1)/n)%2==0){
		cout<<(cnt-1)/n+1<<" "<<(cnt-1)%n+1;
	}if(((cnt-1)/n)%2==1){
		cout<<(cnt-1)/n+1<<" "<<n-(cnt-1)%n;
	}
	return 0;
}
