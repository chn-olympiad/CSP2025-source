#include<bits/stdc++.h>
using namespace std;
int n,m;
int tar;
int a[105];
int c=1,r=1,now=1;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	tar=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tar){
			cout<<c<<" "<<r;
			break;
		}
		r+=now;
		if(r<1){
			now=1;
			c+=1;
			r=1;
		}else if(r>n){
			now=-1;
			c+=1;
			r=n;
		}
	}
	return 0;
}
