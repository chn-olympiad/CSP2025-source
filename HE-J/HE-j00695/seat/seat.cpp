#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int a[105];
int r,k=0;
int kc[11][11];
int x,y;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>a[0];
r=a[0];
for(int i=1;i<=n*m-1;i++){
	cin>>a[i];
	
}
for(int i=0;i<n*m-2;i++){
	for(int j=i+1;j<n*m-1;j++){
		if(a[i]<a[j]){
			
			l=a[i];
			
			a[i]=a[j];
		
			a[j]=l;
			
			
		}
	}

}
for(int i=1;i<=n;){
	for(int j=1;j<=m;j++){
		
		kc[j][i]=a[k];
		if(kc[j][i]==r){
			y=j;
			x=i;
		}
		k++;
	}
	i++;
	for(int j=m;j>=1;j--){
		
	kc[j][i]=a[k];
	if(kc[j][i]==r){
			y=j;
			x=i;
		}
	k++;
	}
	i++;
}
cout<<x<<" "<<y;
return 0;
}

