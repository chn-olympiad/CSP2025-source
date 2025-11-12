#include<bits/stdc++.h>
using namespace std;
int a[110];
int s,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
		a[i]=-a[i];

	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++){
		a[i]=-a[i];
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==s){
					c=i;
					r=j;
					break;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[i*n-(j-n)]==s){
					c=i;
					r=j;
					break;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
