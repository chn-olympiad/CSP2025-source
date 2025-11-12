#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[10][10],p[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>p[i];
	r=p[0];
	sort(p,p+n*m);
	reverse(p,p+n*m);
	int k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[j][i]=p[k];
			k++;
		}
		i++;
		for(int j=n-1;j>=0;j--){
			a[j][i]=p[k];
			k++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]==r){
				cout<<j+1<<" "<<i+1;
				return 0;
			} 
	return 0;
}
