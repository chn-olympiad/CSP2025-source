#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[107],r;
int x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			printf("%d %d",x,y);
			break;
		}
		if(x%2==1)y++;
		else y--;
		if(y>n||y<1){
			if(x%2==1)y=n;
			else y=1;
			x++;
		}
	}
	return 0;
}
