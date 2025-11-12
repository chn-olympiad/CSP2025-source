#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			if(i%n==0){
				x=i/n;
				if(x%2==1){
					cout<<x<<" "<<n;
				}else{
					cout<<x<<" "<<1;
				}
				return 0;
			}else{
				x=i/n+1;
			}
			int b=i%n;
			if(x%2==1){
				y=b;
			}else{
				y=n-b+1;
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
} 