#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int shu,id;
}a[100000005];
bool cmp(node x,node y){
	return x.shu>y.shu;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].shu;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);

	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			if(i%n==0){
				cout<<i/n<<" "; 
				if(i/n%2==0){
					cout<<1;
				}
				else cout<<n;
				break;
			}else
			if(i/n%2==1){
				cout<<i/n+1<<" "<<n-i%n+1;
				
				break;
			}else{
				
				cout<<i/n+1<<" "<<i%n;
				
				break;
			}
		}
	}
	return 0;
} 
