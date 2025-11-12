#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)
			s=a[1];
	}
	sort(a+1,a+n*m+1,greater<int>());
	int x=0,y=0;	 
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			if(i%n!=0)
				y=i/n+1;
			else
				y=i/n;
			if(y%2==0){
				x=n-(i-(y-1)*n)+1;
			}
			else{
				x=(i-(y-1)*n);
			}
			cout<<y<<" "<<x;
			break;	
		}
	}	
	return 0;
}
