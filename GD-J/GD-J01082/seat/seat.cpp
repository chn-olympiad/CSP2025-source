#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],x,c;
int p,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			c=n*m-i+1;
			break;
		} 
	}
	if((c%n)!=0){
		q=c/n+1;
		if(q%2==0){
			p=n-c%n+1;
		}else{
			p=c%n;
		}
	}else{
		q=c/n;
		p=n;
	}
	cout<<q<<" "<<p;
}
