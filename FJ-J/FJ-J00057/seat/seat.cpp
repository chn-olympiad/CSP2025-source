#include<bits/stdc++.h>
using namespace std;
inline bool cmp(int x,int y){
	return x>y;
}
int n,m,a[101],x,f,y;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i*m+j];
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(a[i]==x){
			f=i;
			break;
		}
	}
	y=f%n+1;
	f/=n;
	f++;
	if(f%2)cout<<f<<" "<<y;
	else cout<<f<<" "<<n-y+1;
	return 0;
}
