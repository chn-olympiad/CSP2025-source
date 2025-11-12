#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,N;
	cin>>n>>m;
	N=n*m;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+N+1);
	int x=0,y=1;
	for(int i=N;i>=1;i--){
		if(y%2==1){
			x++;
		}
		else{
			x--;
		}
		if(x>n){
			y++;
			x--;
		}
		else if(x<1){
			y++;
			x++;
		}
//		cout<<y<<" "<<x<<"\n";
		if(a[i]==s){
			break; 
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
