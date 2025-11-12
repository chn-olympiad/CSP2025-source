#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int b[105];
int main(){
	cin>>n>>m;
	int sum;
	
	for(int i=1;i<=n*m;i++)
			cin>>b[i]; 
	if(n*m==1){
		cout<<"1 1";
		return 0;
	}
	sum=b[1];
	sort(b+1,b+n*m+1);
	int f=1;
	bool s=true;
	int i=1,j=1;
		
	while(j<=n&&i<=m){
		a[i][j]=b[f];
		if(s){
			if(a[j][i]==sum){
			cout<<j<<' '<<i;
			return 0;
			}
			else{
				j++;
				f++;
			} 
		}
		if(!s){
			if(a[j][i]==sum){
				cout<<j<<' '<<i;
				return 0;
		}
			else{
				j--;
				f++;
			} 
		}
		if(j>n){
			j=n;
			i++;
			s=false;
		}
		if(j<1){
			j++;
			i++;
			s=true;
		}
		
	}
		
	
	
	return 0;
}

