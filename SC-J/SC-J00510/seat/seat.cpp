#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,y_=1;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int a1=a[1],t;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			t=n*m-i+1;
			break;
		}
	}if(t==1){
		cout<<1<<" "<<1;
		return 0;
	}for(int i=1;i<=t-1;i++){
		if(y==n&&y_==1){
			x++;
			y_=-1;
		}else if(y==1&&y_==-1){
			x++;
			y_=1;
		}else{
			y+=y_;
		}
	}cout<<x<<" "<<y;
	return 0;
}