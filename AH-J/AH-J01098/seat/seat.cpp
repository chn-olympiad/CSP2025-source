#include <bits/stdc++.h>
using namespace std;
int a[1001];
int cmp(int x,int y){
		return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		
		if(a[i]==k){
		
			int t2=i/n;
			if(t2*n!=i){
				t2++;
			}
			int t=i-n*(t2-1);
			cout<<t2<<" ";
			if(t2%2==0){
				cout<<n-t+1;
			}else{
				cout<<t;
			}
			return 0;
		}
	}
	return 0;
}
