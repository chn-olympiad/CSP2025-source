#include<bits/stdc++.h>
using namespace std;
int n,m,nodem;
int a[110],b[50][50];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>nodem;
	a[1]=nodem;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int k=1,step=0;
	if(a[1]==nodem){
		cout<<1<<" "<<1;
		return 0;
	}
	if(a[n*m]==nodem){
		cout<<m<<" "<<n;
		return 0;
	}
	int x=1,y=1;
	for(int i=1;i<=m/2+1;i++){
		while(x!=n){
			b[x][y]=a[k];
			if(a[k]==nodem){
				cout<<y<<" "<<x;
				return 0;
			}
			x++;
			k++;
		}
		k++;
		b[x][y]=a[k];
		if(a[k]==nodem){
			cout<<y<<" "<<x;
			return 0;
		}	
		y++;
		while(x!=1){
			k++;
			b[x][y]=a[k];
			if(a[k]==nodem){
				cout<<y<<" "<<x;
				return 0;
			}
			x--;
		}
		k++;
	}
	return 0;
}
