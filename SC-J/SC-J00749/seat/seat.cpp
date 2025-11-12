#include<bits/stdc++.h>
using namespace std;
const int Maxn=110;
int a[Maxn],g[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
	int n=0,m=0;
	bool d=true;
	cin >> n >> m;
	for(int i=0;i<n*m;i++) cin >> a[i];
	int h = a[0];
	sort(a,a+n*m,cmp);
	int k=0;
	for(int i=0;i<m;i++){
		if(d){
			for(int j=0;j<n;j++) g[j][i] = a[k++];
			d=false;
		}else{
			for(int j=n-1;j>=0;j--) g[j][i] = a[k++];
			d=true;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(g[i][j] == h) cout << j+1<<" " << i+1;
		}
		
	}
	
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) cout << g[i][j] << " ";
		cout << endl;
	}
	*/
	return 0;
}