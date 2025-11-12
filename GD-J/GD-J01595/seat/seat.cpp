#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ansx;
	int ansy;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	int da=n*m;
	sort(a+1,a+da+1,greater<int>());
	int man;
	for(int i=1;i<=da;i++){
		if(sum==a[i]){
			man=i;
		}
	}
	if(man<=n){
		ansx=1;
		ansy=man;
	}else{
		int x=man/n;	
		if(man%n==0){
			ansx=x;
			if(x%2==1){
				ansy=n;
			}else{
				ansy=1;
			}
		}else{
			if(x%2==1){
				ansx=x+1;
				ansy=n-(man-n*x)+1;
			}else{
				ansx=x+1;
				ansy=man-n*x;
			}
		}
			
	}
	
	cout<<ansx<<" "<<ansy;
	return 0;
}
