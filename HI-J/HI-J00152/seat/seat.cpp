#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,q[15];
	cin >> n >> m;
	int k=n*m;
	if(n==1&&m==1){
		cout << 1 << " " << 1;
	}
	else if(n==1 && m<=10){
		for(int i=1;i<=k;i++){
			cin >> q[i];
			r=q[1];
		}
		sort(q+1,q+1+k,cmp);
		for(int i=1;i<=k;i++){
			if(q[i]==r){
				cout << i << " " << 1;
			}
		}
	}
	else if(m==1 && n<=10){
		for(int i=1;i<=k;i++){
			cin >> q[i];
			r=q[1];
		}
		sort(q+1,q+1+k,cmp);
		for(int i=1;i<=k;i++){
			if(q[i]==r){
				cout << 1 << " " << i;
			}
		}
	}
	else if(n==2&&m==2){
		int bj45=0;
		for(int i=1;i<=k;i++){
			cin >> q[i];
			r=q[1];
		}
		sort(q+1,q+1+k,cmp);
		for(int i=1;i<=k;i++){
			if(q[i]==r){
				bj45=i;
			}
		}
		if(bj45<=2){
			cout << 1 << " " << bj45;
		}
		else if(bj45==3){
			cout << 2 << " " << 2;
		}
		else cout << 2 << " " << 1;
	}
	return 0;
}
