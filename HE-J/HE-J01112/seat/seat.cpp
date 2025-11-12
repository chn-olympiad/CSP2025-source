#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+cnt+1);
	for(int c=1;c<=m;c++){
		if(c%2){
			for(int r=1;r<=n;r++){
				if(a[cnt--]==x){
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
		if(c%2==0){
			for(int r=n;r;r--){
				if(a[cnt--]==x){
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
	}
	return 0;
} 
