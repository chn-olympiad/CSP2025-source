#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,k;
}a[110];
int n,m,p;
bool cmp(node a,node b){
	return a.s>b.s;
}
void ck(int q){
	int l,h;
	if(q%n==0) {
		l=q/n;
		cout<<l<<" "<<n;
		return;
	}
	l=q/n+1;
	int lh=q-(n*(l-1));
	if(l%2==0){
		h=n+1-lh;
	}
	else h=lh;
	cout<<l<<" "<<h;
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	p=n*m;
	for (int i=1;i<=p;i++){
		cin>>a[i].s;
		a[i].k=i;
	}
	
	sort(a+1,a+p+1,cmp);

	for (int i=1;i<=p;i++){
		if(a[i].k==1){
			ck(i); 
			return 0;
		}
	}
} 
