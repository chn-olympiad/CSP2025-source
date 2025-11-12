#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	int cutm=n*m;
	for(int i=1;i<=cutm;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}
	sort(a+1,a+cutm+1,cmp);
	for(int i=1;i<=cutm;i++){
		if(a[i]==k){
			if(i%n==0){
				cout<<i/n<<" ";
				if((i/n)%2!=0) cout<<n;
				else cout<<1;
			}
			else{
				cout<<i/n+1<<" ";
				if((i/n+1)%2!=0) cout<<i%n;
				else cout<<(n+1)-(i%n);
			}
			break;
		}
	}
	return 0;
}
