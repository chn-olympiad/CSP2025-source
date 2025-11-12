#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int id;
}a[10005];
int n,m;
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num ;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			if((i/n)%2==0){
				if(i%n!=0)
				cout<<i/n+1<<" "<<i%n;
				else
				cout<<i/n<<" "<<n;
			}
			else{
				if(i%n!=0)
				cout<<i/n+1<<" "<<n-i%n+1;
				else
				cout<<i/n<<" "<<1;
			}
			break;
		}
	}
	return 0;
}
