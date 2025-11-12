#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int grade;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	grade=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==grade){
			int x=i/n,y;
			if(i%n==0){
				if(x%2==1){
					y=n;
				}else{
					y=1;
				}
			}else{
				x++;
				if(x%2==1){
					y=i%n;
				}else{
					y=n-i%n+1;
				}
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
