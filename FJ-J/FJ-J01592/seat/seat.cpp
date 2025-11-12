#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005];
int n,m,q;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	int b=a[1],c=0;
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout <<a[i]<<" ";
//	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
		}
	}
//	cout <<c;
	if(c<=n){
		cout<<1<<" "<<c;
	}else if(c>n){
		if(c%n==0){
			q=c/n;
		}else{
			q=c/n+1;
		}
		cout <<q<<" ";
		if(q%2!=0){
			cout <<c-(q-1)*n;
		}else{
			cout <<m+(q-1)*n-c+1;
		}
	}
	return 0;
}
