#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1],b[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int q=b[1],w;
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(q==b[i]){
			w=i;
		}
	}
	int u=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int q=1;q<=n;q++){
				a[q][i]=u;
				u++;
	        }
		} 
		else{
			for(int q=n;q>0;q--){
				a[q][i]=u;
				u++;
	        }
		}
	}
	for(int i=1;i<=n;i++){
		for(int q=1;q<=m;q++){
			if(a[i][q]==w){
				cout<<q<<" "<<i;
				return 0;
			}
		} 
	}
	return 0;
} 