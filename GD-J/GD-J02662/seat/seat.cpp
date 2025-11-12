#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100100],js,ans,w;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			w=i;
			break;
		}
	}
	int k=w%n;
	int p=w/n;
	if(k==0){
		if(p%2==0){
			cout<<p<<" "<<1;
			return 0;
		}
		cout<<p<<" "<<n;
		return 0;
	}
	if(k!=0){
		p++;
		if(p%2==0){
			cout<<p<<" "<<n-k+1;
			return 0;
		}
		cout<<p<<" "<<k;
		return 0;
	}
}

