#include<bits/stdc++.h>
using namespace std;
int n,m,b[105],x,y=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int q=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(q==b[i]){
			q=i;
			break;
		}
	}
	while(1){
		if(q>n){
			q-=n;
			y++;
		}else{
			if(y%2==1){
				x=q;
			}else{
				x=n-q+1;
			}
			break;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}