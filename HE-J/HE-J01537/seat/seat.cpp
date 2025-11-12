#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN];
int b[MAXN][MAXN];
int main(){
	freopen("seat".in,"r","stdin");
	freopen("seat".out,"w","stdout");
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j-1]<a[j])swap(a[j-1],a[j]);
		}
	}
	int Ra=0;
	for(int i=0;i<n*m;i++){
		if(R==a[i])Ra=i+1;
	}
	int x=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++){
		b[j][0]=a[x];
			x++;
		}
		x--;
		i++;
		for(int j=n-1;j>=0;j--){
			b[j][1]=a[x];
			x++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==R){
				cout<<j+1<<" "<<i+1;
			}
		}
		cout<<endl;
	}
return 0;
}
