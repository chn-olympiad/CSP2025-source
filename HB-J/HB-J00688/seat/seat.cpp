#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],p,cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(p==a[i]){
			cnt=i;
			break;
		}
	}
	int y=cnt%n;
	int x=(cnt-y)/n;
	if(y>=1){
		if(x%2==0){
			cout<<x+1<<" "<<y;
			return 0;
		}
		else{
			cout<<x+1<<" "<<n-y+1;
		}
	}
	else{
		if(x%2==1){
			cout<<x<<" "<<n;
		}
		else{
			cout<<x<<" "<<1;
		}
	}
	return 0;
}
