#include <bits/stdc++.h>
using namespace std;
struct node{
	int c;
	bool s;
};
bool cmp(node x,node y){
	return x.c>y.c;
}
node k[101];
int n,m,g;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	g=n*m;
	for(int i=1;i<=g;i++){
		cin>>k[i].c;
		k[i].s=0;
		if(i==1){
			k[i].s=1;
		}
	}
	sort(k+1,k+1+g,cmp);
	int x,y;
//	cout<<n<<endl;
	for(int i=1;i<=n*m;i++){
		if(k[i].s==1){
			if(i%n!=0){
				x=i/n+1;
				y=i%n;
			}
			else{
				x=i/n;
				y=n;
			}
			cout<<x<<' ';
			if(x%2==1){
				cout<<y;
			}
			else{
				cout<<n-y+1;
			}
		}
	}
	return 0;
}

