#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1005];
int temp;
int x,y;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	temp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i<=n*m;i++){
		if(temp==a[i]){
			x=(i-1)/n+1;
			if(x%2==1){
				y=(i-1)%n+1;
			}
			else{
				y=n-(i-1)%n;
			}
			break;
		}
	
	}
	cout<<x<<" "<<y;
	return 0;
}
