#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct node{
	int id,num;
};
node a[100005];
int now;
bool cmp(node x,node y){
	return x.num>y.num;
} 
int main(){
//	ios_sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].id=i;
		cin>>a[i].num;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			now=i;
			break;
		}
	}
	cout<<now/n+!(now%n==0)<<" ";
//	cout<<now<<endl;
	if((now/n+!(now%n==0))%2==0){
		if(now%n==0){
			cout<<1;
		}else{
			cout<<n-now%n+1;
		}
	}else{
		if(now%n==0){
			cout<<n;
		}else{
			cout<<now%n;
		}
	}
	return 0;
}

