#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int x,y;
struct node{
	int id;
	int s;
}a[105];
int cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1) a[i].id=1;
		cin>>a[i].s;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			if(i%n==0){
				if((i/n)%2==1){
					cout<<i/n<<" "<<n;
				}
				else cout<<i/n<<" "<<1;
				break;
			}
			else{
				if((i/n+1)%2==1){
					x=i/n+1;
					y=i%n;
				}
				else{
					x=i/n+1;
					y=m+1-i%n;
				}
				break;
			}
		}
	}	
	cout<<x<<" "<<y<<endl;
	return 0;
}
