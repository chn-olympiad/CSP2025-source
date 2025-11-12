#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r1;
	cin>>r1;
	a[0]=r1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	int c=1,r=1;
	bool z=0;
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==r1){
			cout<<c<<' '<<r;
			return 0;
		}
		if(r%n==0&&c%2==1){
			z=1;
			r++;
			c+=1;
		}
		if(r==1&&c%2==0){
			z=0;
			r=0;
			c+=1;
		}
		if(z) r--;
		else r++;
	}
	return 0;
}
