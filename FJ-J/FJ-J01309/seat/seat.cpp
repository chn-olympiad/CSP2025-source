#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
struct d{
	int s;
	int mn;
}a[111];
int p(d x,d y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].mn=i;
	}
	int f=m*n;
	sort(a+1,a+1+f,p);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans++;
				if(a[ans].mn==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ans++;
				if(a[ans].mn==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
