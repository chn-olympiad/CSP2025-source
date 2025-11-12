#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,id;
}a[10010];
int n,m;
bool cmp(Node x,Node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int tmp;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			tmp=i;
			break;
		}
	}
	int ans1=tmp/n;
	if(ans1*n==tmp){
		if(ans1%2==1) cout<<ans1<<" "<<n<<endl;
		else cout<<ans1<<" "<<1<<endl;
	}
	else{
		if((ans1+1)%2==1) cout<<ans1+1<<" "<<tmp%n<<endl;
		else cout<<ans1+1<<" "<<n-tmp%n+1<<endl;
	}
	return 0;
}
