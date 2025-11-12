#include<bits/stdc++.h>
using namespace std;
bool bj(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	int a[n*m+5],t[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	sort(t+1,t+n*m+1,bj);
	int bh;
	for(int i=1;i<=n*m;i++){
		if(a[1]==t[i]) {
			bh=i;
			break;
		}
	}
	r=bh/n;//lie
	c=bh%n;//hang
	if(bh%n!=0) r+=1;
	if(r%2==0){		//n-1
		if(c==0) c=1;
		else{
			int k=1;
			for(int i=n;i>=1;i--){
				if(k==c) {
					c=i;
					break;
				}
			}
		}
		
	}
	else{		//1-n
		if(c==0) c=n;
	}
	cout<<r<<" "<<c;
	return 0;
}
