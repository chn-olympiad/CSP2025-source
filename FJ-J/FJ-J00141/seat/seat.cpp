#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,id;
}q[100001];
int cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i].num;
		q[i].id=i;
	}
	sort(q+1,q+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(q[i].id==1){
			int k=i/n;
			if(k%2==0){
				if(i%n==0) cout<<k<<" "<<1;
				else cout<<k+1<<" "<<i%n;
			}
			else{
				if(i%n==0) cout<<k<<" "<<n;
				else cout<<k+1<<" "<<n-i%n+1;
			}
			return 0;
		}
	}
	return 0;
} 
