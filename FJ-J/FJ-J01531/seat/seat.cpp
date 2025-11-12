#include<bits/stdc++.h>
using namespace std;
int a[1000],m,n,q=1,w=1,k=1;
int b[20][20];
string s;
bool cmp(int y,int x){
	return y>x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int u=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m;i++){
	if(q<n){
	for(int j=1;j<=n;j++){
		b[w][q]=a[k];
		k++;
		if(q<n)
		q++;
	}
	w++;	
	}
	if(q==n){
	for(int j=n;j>=1;j--){
		b[w][q]=a[k];
		k++;
		if(q>1)
		q--;
	}
	w++;	
}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==u){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
} 
