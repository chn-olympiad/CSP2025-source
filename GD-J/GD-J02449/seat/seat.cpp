#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],xj,x,y;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xj=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==xj){
//			cout<<i;
			xj=i;
			break;
		}
	}
	//cout<<xj;
	x=(xj+n-1)/n;
	if(x%2==1){
		if(xj%n!=0)  y=+xj%n;
		else y=n;
	}else{
		if(xj%n!=0) y=n-xj%n+1;
		else y=1;
	}
	cout<<x<<' '<<y;
	return 0;
} 
