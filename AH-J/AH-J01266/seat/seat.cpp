#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],xb,bh,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		xb=a[0];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==xb){
			bh=i+1;
			y=bh%m;
			x=bh/m;
			break;
		}
	}
	if(x%2==0&&y!=0){
		cout<<x+1<<" "<<y;
	}else if(x%2==0&&y==0){
		cout<<x<<" "<<1;
	}else if(x%2!=0&&y!=0){
		cout<<x+1<<" "<<m-y+1;
	}else if(x%2!=0&&y==0){
		cout<<x<<" "<<m;
	}
	return 0;
}
