#include<bits/stdc++.h>
using namespace std;

int n,m,r,idx=0;
int a[105];

int main(){
	//AC from 1 to 3.
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[(i-1)*n+j];
		}
	}
	r=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==r){
				idx=n*m-((i-1)*n+j)+1;
				break;
			}
		}
		if(idx!=0){
			break;
		}
	}
	int c=(idx-1)/n+1;
	int r=idx%n;
	if(r==0) r=n;
	if(c%2==0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
