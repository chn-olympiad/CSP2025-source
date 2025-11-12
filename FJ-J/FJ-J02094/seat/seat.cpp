#include <bits/stdc++.h>
using namespace std;
int n,m,r,c;
int a[145],R;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			c=(i-1)/n+1;
			if(c%2==1){
				r=(i-1)%n+1;
			}else{
				r=(n*2)-((i-1)%(n*2));
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
