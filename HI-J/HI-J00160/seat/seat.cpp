#include<bits/stdc++.h>
using namespace std;
const int N=15*15;
int a[N];
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int a1=a[1],r=1,c=1;
	for(int i=1;i<=n*m;i++){
		if(a1<a[i]&&c%2==1){
			r++;
			if(c<m&&r==n){
				c++;
			}
		}else if(a1<a[i]&&c%2==0){
			r--;
			if(c<m&&r==1){
				c++;
			}
		}
	}
	cout<<c<<' '<<r; 
	return 0;
}
