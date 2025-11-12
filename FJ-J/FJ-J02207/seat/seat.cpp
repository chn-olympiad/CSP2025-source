#include<bits/stdc++.h>
using namespace std;
int n,m,l;
struct node{
	int x,y;
}a[105];
bool comp(node a1,node a2){
	return a1.x>a2.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,comp);
	for(int i=1;i<=n*m;i++){
		if(a[i].y==1){
			l=i;
			break;
		}
	}
	if(l%n==0&&(l/n)%2==1){
		cout<<l/n<<" "<<n;
	}
	else if(l%n!=0&&(l/n)%2==0){
		cout<<l/n+1<<" "<<l%n;
	}
	else if(l%n==0&&(l/n)%2==0){
		cout<<l/n<<" 1";
	}
	else cout<<l/n+1<<" "<<n+1-l%n;
	return 0;
}
