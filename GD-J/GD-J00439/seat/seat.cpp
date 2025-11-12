#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[15][15];
ll a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	int a2;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a2=n*m-i+1;
			break;
		}
	}
	int x=(a2+m-1)/m;
	int y;
	if(x%2==1){
	
		if(a2%m==0){
			y=m;
		}else{
			y=a2%m;
		}
	}else{
		if(a2%m==0){
			y=1;
		}else{
			y=m-a2%m+1;
		}
	}
	cout<<x<<' '<<y;
	return 0;
} 
