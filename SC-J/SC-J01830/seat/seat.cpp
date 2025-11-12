#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int Xr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	Xr=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==Xr){
			if((i-1)/n%2!=0){
				if(i%n==0){
					cout<<(i+n-1)/n<<" "<<1<<"\n";
				}
				else cout<<(i+n-1)/n<<" "<<n-i%n+1<<"\n";
			}else{
				if(i%n==0){
					cout<<(i+m-1)/m<<" "<<n<<"\n";
				}
				else cout<<(i+m-1)/m<<" "<<i%n<<"\n";
			}
			break;
		}
	}
	return 0;
}