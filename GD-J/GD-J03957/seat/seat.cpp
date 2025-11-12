#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int cz;
	int z=0;
}a[200];
bool cmp(Node x,Node y){
	return x.cz>y.cz;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cz;
		if(i==1){
			a[i].z=1;
		}
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].z==1){
			if(i%n==0){
				cout<<i/n<<' ';
				if((i/n)%2==1){
					cout<<n;
				}else{
					cout<<1;
				}
			}else{
				cout<<i/n+1<<' ';
				if((i/n+1)%2==1){
					cout<<i%n; 
				}else{
					cout<<n-i%n+1;
				}
			}
		}
	}
	return 0;
} 
