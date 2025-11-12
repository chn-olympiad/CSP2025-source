#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}w[105];
bool cmp(node x,node y){
	return x.a>=y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int j=n*m;
	for(int i=1;i<=j;i++){
		cin>>w[i].a;
		w[i].b=i;
	}
	sort(w+1,w+j+1,cmp);
	int r;
	for(int i=1;i<=j;i++){
		if(w[i].b==1){
			r=i;
			break;
		}
	}
	int x,y; 
	if(r%n==0)x=r/n;
	else x=r/n+1;
	if(x%2==1){
		if(r%n==0)y=n;
		else y=r%n;
	}
	else {
		if(r%n==0)y=n-n+1;
		else y=n-r%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
}

