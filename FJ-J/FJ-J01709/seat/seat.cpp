#include<bits/stdc++.h>
using namespace std;
int seat[11][11]={0},a,n,m,r,t[105]={0},f[105]={0},maxn=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	t[r]=1;
	for(int i=0;i<n*m-1;i++){
		cin>>a;
		t[a]=1;
		if(maxn<a){
			maxn=a;
		}
	}
	int z=0;
	for(int i=maxn+10;i>0;i--){
		if(t[i]==1){
			f[z]=i;
			z++;
		}
	}
	z=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			seat[j][i]=f[z];
			z++;
		}
		i++;
		for(int x=m-1;x>=0;x--){
			seat[x][i]=f[z];
			z++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(seat[i][j]==r){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}
