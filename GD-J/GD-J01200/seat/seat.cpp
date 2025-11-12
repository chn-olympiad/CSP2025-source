#include<bits/stdc++.h>
using namespace std;
const int N= 40;
int a[N][N],b[N*N],c[N][N];
bool cmp(int c,int d){
	return c>d; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[++q]=a[i][j];
		}
	}
	int pm=0;
	sort(b+1,b+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(b[i]==a[1][1]){
			pm=i;
			break;	
		}
	}
	if(n==1){
		cout<<1<<" "<<pm;
		return 0;
	} 
	int oo=0;
	bool f=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[i][j]=b[++oo];
				if(b[pm]==c[i][j]){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
			}
			if(f==1)break;
		}
		else{
			for(int j=n;j>=1;j--){
				c[i][j]=b[++oo];
				if(b[pm]==c[i][j]){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
			}
			if(f==1)break;
		}
	} 
	
	return 0;
}
