#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,b,c;
struct node{
	int vvv,x;
}a[1100];
int cmp(node l,node r){
	if(l.x!=r.x) return l.x>r.x;
	else return l.vvv<r.vvv;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i].x;
		a[i].vvv=i;
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(a[i].vvv==1){
			t=i;
			break;
		} 
	}
	c=t/n;
	if(t%n!=0) c++;
	else{
		if(c%2==0) cout<<c<<" 1";
		else cout<<c<<" "<<n;
		return 0;
	}
	t=t%n;
	if(c%2==0){
		cout<<c<<" "<<n-t+1;
	}else{
		cout<<c<<" "<<t;
	}
	return 0;
}
