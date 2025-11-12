#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,id;
}a[105];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	int k=a[1].x;
	int q;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].x==k){
			q=i;
			break;
		}
	}
	if(q%n==0){
		cout<<q/n<<" ";
		q/=n;
		if(q%2==0){
			cout<<1;
		} 
		else{
			cout<<n;
		}
	}
	else{
		cout<<q/n+1<<" ";
		if((q/n+1)%2==0) cout<<n-q%n+1;
		else cout<<q%n;
	}
	return 0;
}
