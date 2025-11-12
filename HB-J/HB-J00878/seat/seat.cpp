#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int k,l,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[150],b[15][15];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				l++;
				b[l][i]=a[k];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				k++;
				b[l][i]=a[k];
				l--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==p) cout<<j<<" "<<i;
		}
	}
	
	return 0;
}
