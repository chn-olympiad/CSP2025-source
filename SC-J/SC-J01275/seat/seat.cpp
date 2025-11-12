#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int cnt;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		cnt=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0){
		int sum=cnt/n;
		if(sum%2==0){
			cout<<sum<<" "<<1;
		}
		else{
			cout<<sum<<" "<<n;
		}
	}
	else{
		int sum=cnt/n+1;
		int k=cnt%n;
		if(sum%2==0){
			cout<<sum<<" "<<n-k+1;
		}
		else{
			cout<<sum<<" "<<k;
		}
	}
	return 0;
} 