#include<bits/stdc++.h>
using namespace std;

int m,n,wayy;
int a[15][15];
int s[500],ton[150];

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int aa=s[1];
	int o=1;
	
	for(int i=1;i<=m*n;i++){
		ton[s[i]]++;
	}
	for(int i=100;i>=1;i--){
		for(int j=1;j<=ton[i];j++){
			s[o]=i;
			o++; 
		}
	}
	
	o=1;
	for(int i=1;i<=m;i++){
		if(wayy==0){
			for(int j=1;j<=n;j++){
				a[j][i]=s[o];
				o++;
			}
			wayy=1;
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=s[o];
				o++;
			}
			wayy=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]==aa){
				cout<<i<<" "<<j;
			}
		}
		
	}

	return 0;
} 
