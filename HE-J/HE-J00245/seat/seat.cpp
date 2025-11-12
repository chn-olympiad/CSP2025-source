#include<bits/stdc++.h>
using namespace std;
struct Node{
	int idd,ans;
}a[105];
int n,m,k,x,y;
bool cmp(Node b,Node c){
	return b.ans>c.ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].ans;
		a[i].idd=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].idd==1){
			k=i;
		}
	}
	if(k%n==0){
		y=k/n;
	}else{
		y=k/n+1;
	}
	if(y%2==1){
		if(k%n==0){
			x=n;
		}else{
			x=k%n;
		}
	}else{
		if(k%n==0){
			x=1;
		}else{
			x=n-(k%n)+1;
		}
		
	}
	cout<<y<<' '<<x;
	return 0; 
} 
