#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a,j;
}q[1001];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i].a;
		q[i].j=i;
	}
	sort(q+1,q+n*m+1,cmp);
	int sum=0;
	for(int i=1;i<=n*m;i++){
		if(q[i].j==1){
			sum=i;
		}
	}
	int h=sum/n;
	if(sum%n==0){
		cout<<h<<" ";
		if(h%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<h+1<<" ";
		if(h%2==0){
			cout<<sum%n;
		}else{
			cout<<n-(sum%n)+1;
		}
	}
	return 0;
}

