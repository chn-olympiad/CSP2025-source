#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int cnt;
int r=1,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}for(int i=2;i<=cnt+1;i++){
		if(c%2==1&&r<n){
			r++;
		}else if(c%2==1&&r==n){
			c++;
		}else if(c%2==0&&r>1){
			r--;
		}else if(c%2==0&&r==1){
			c++;
		}
	}cout<<c<<' '<<r;
	return 0;
}