#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			int x=0,y=0;
			x=i/n;
			if(i%n!=0){
				x+=1;
				if(x%2==0){
					y=n-i%n+1;
				}
				else{
					y=i%n;
				}
				cout<<x<<" "<<y;
				return 0;
			}
			else if(i%n==0){
				if(x%2!=0){
					y=n;
				}
				else{
					y=1;
				}
				cout<<x<<" "<<y;
				return 0;
			}
		}
	}
}