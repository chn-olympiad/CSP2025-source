#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a2,b,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)a2=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a2){
			b=i;
			break;
		}
	}
	if(b%m==0){
		c=b/m;
	}		
	else c=b/m+1;
	if(b%(n*2)>=1&&b%(n*2)<=n){
		r=b%(n*2);
	}
	else{
		r=abs(n-b%(n*2)+n+1);
	}
	cout<<c<<" "<<r;
	return 0;
}
