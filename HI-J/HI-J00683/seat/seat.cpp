#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[108];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int qwe=n*m;
	for(int i=1;i<=qwe;i++){
		cin >> a[i];
	}
	int ert=a[1];
	sort(a+1,a+qwe+1);
	for(int i=qwe;i>=1;i--){
		if(a[i]==ert){
			int ax=qwe-i+1;			
			int sum=ceil(ax*1.0/n);
			if(ax<=n){
				cout << 1 << " " << ax;
				return 0;
			} 				
			else if(sum%2==0){
				int sum1=ax%n+1;
				cout << sum << " " << sum1; 
				return 0;
			}
			else{
				int sum1=ax%n;
				cout << sum << " " << sum1; 
				return 0;
			}
		}
	}
	return 0;
}

