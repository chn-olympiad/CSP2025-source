#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[110];
int l=1,r=0;
void f(int bd,int num,int k){
	if(num==1&&k==1) r++;
	if(num==1){
		
		a[l][r]=bd;
		l++;
		return ;
	}
	if(k==1){
		r++;
		l--;
		a[l][r]=bd;
		return ;
	}
	l--;
	a[l][r]=bd;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,y;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>b[i];
		if(i==1) y=b[i];
	} 
	sort(b+1,b+x+1);
	int j=1,k=0;
	for(int i=x;i>=1;i--){
		k++;
		if(j%2==1){
			f(b[i],1,k);
		}else{
			f(b[i],2,k);
		}
		if(k==n){
			k=0;
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==y) cout<<j<<" "<<i;
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}


	
}
