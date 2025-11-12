#include <bits/stdc++.h>
using namespace std;
int n,m,s,xs=0,ys=1,f=0;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int d;
		cin>>d;
		if(i==1){
			s=d;	
		}
		a[d]++;
	}
	int cnt=0;
	for(int i=100;i>=0;i--){
		if(a[i]){
			cnt++;
		}
		if(i==s&&a[i]){
			ys=(cnt+n-1)/n;
			int l=0;
			for(int j=1;j<=cnt;j++){
				if(l){
					l--;
					continue;
				}
				if(f==0){
					xs++;
				}
				else{
					xs--;
				}
				if(j%n==0){
					f++;
					f%=2;
					l++;
					continue;
				}
			}
		}
	}
	cout<<ys<<" "<<xs;
	return 0;
}
