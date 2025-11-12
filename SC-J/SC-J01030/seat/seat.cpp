#include<bits/stdc++.h>
using namespace std;
int n,m,a[19][19],b[109],c[109];


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int o=n*m;
	for(int i=1;i<=o;i++){
		cin>>b[i];
	}
	int p=b[1],u;
	sort(b+1,b+1+o);
	for(int i=o;i>=1;i--){
		c[o-i+1]=b[i];
	}
//	for(int i=1;i<=o;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
	int x,y;
	bool f=1;
	int i=1,j;
	for(int k=1;k<=o;k++){
		if(k>=2&&(k-1)%n==0)i++;
		if(i%2==1){
			if(k%n==0)j=n;
			else j=k%n;
//			cout<<i<<" "<<j<<endl;
			a[j][i]=c[k];
		} 
		else if(i%2==0){
			if(k%n==0)j=1;
			else j=n-k%n+1;
//			cout<<i<<" "<<j<<endl;
			a[j][i]=c[k];
		}
			if(c[k]==p){
				x=i;
				y=j;
				f=0;
			}
			if(f==0)break;
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<x<<" "<<y;
	
	return 0;
} 