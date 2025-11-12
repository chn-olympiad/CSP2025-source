#include<bits/stdc++.h>
using namespace std;
int now,a[105],top=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])top++;
		if(i==1){
			now=a[1];
		}
	} 
	//cout<<"top: "<<top<<"\n";
	int r=top%n,c=(top-(top%n))/n;
	if(c%2==0){//1->n 
		if(r==0){
			cout<<c<<" 1";
		}else{
			cout<<c+1<<" "<<r;
		}
	}
	if(c%2==1){//n->1
		if(r==0)cout<<c<<" "<<m;
		else cout<<c+1<<" "<<m-r+1;
	}
	return 0;
} 
