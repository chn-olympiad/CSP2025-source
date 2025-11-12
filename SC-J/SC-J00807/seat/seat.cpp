#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long o=m*n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	long long xr=a[1];
	sort(a+1,a+1+o);
	long long wz=0;
	for(int i=o;i>=1;i--){
		if(a[i]==xr){
			wz=o-i+1;
		}
	}
//	cout<<wz<<"\n";
	if(wz/n%2==0){
		if(wz/n==0){
			cout<<1<<" "<<wz;
		}else{
			if(wz%n==0){
				cout<<wz/n<<" "<<1;
			}else{
				cout<<wz/n+1<<" "<<wz%n;
			}
		}
	}else{
		if(wz%n==0){
			cout<<wz/n<<" "<<n;
		}else{
			cout<<wz/n+1<<" "<<n-wz%n+1;
		}
	}
	
	return 0;
}