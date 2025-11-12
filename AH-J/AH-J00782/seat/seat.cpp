#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,l,a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			l=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			x=i/n;
			if(i%n!=0){
				x++;
			}
			y=i%n;
			if(y==0){
				y=n;
			}
			if(x%2==0){
				y=n-y+1;
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
