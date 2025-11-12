#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,x,b,c;
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		a[i]*=-1;
	}x=a[0]*-1;
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		a[i]*=-1;
	}
	for(int i=1;i<=m;i++){
		if(a[i*n-1]<=x&&a[i*n-n]>=x){
			for(int j=1;j<=n;j++){
				if(a[i*n-j]==x){
					b=i;
					if(i%2==1)c=n+1-j;
					if(i%2==0)c=j;
				}
			}
		}
	}
	cout<<b<<' '<<c;
	return 0;
}
