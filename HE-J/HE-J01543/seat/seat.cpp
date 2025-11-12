#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int w=b[1];
	int h=0;
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(b[i]==w){
			h=i;
		}
	}
	int r=n*m+1-h;
	int q=0;
	if(r%n==0){
		q=r/n;
		cout<<q<<" ";
		if(q%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
		return 0;
	}else{
		q=r/n+1;
	}
	cout<<q;
	if(q%2==0){
		cout<<" "<<n+1-r%n;
	}else{
		cout<<" "<<r%n;
	}
	return 0;
}
