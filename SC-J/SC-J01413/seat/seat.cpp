#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],x,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[(j-1)*n+i]==x){
					r=j;
					c=i;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[j*n-i+1]==x){
					r=j;
					c=i;
				}
			}
		}
	} 
	cout<<c<<' '<<r;
	return 0;
}