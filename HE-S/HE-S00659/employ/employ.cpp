#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<=m;i++){
		int c[n];
		cin>>c[n];
		for(int j=0;j<=m;j++){
			int d[n];
			cin>>d[n];
			if((c[n]&-1)<=(d[n]&-1)){
				sum++;
				break;
			}
		}
		
	}
	
	if(sum>=m){
		cout<<m;
	}
	else{
		cout<<sum;
	}
		  
	

 
	

	return 0;
}
