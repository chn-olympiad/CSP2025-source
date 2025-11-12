#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>

using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	int n,m,index=0;
	cin>>n>>m;
	vector<vector<int> > vec(n,vector<int>(m,0));
	vector<int> in;
	for(int i=0;i<=m*n-1;i++){
		cin>>in[i];
	}
	index=in[0];
	for(int i=0;i<=m*n-1;i++){
		for(int j=0;j<=m*n-1;j++){
			if(in[i]<in[j]){
				swap(in[i],in[j]); 
			}
		}
	}
	
	for(int i=0;i<=m-1;i++){
	 if(i%2==0){
			for(int j=0;j<=n-1;j++){
				for(int k=0;k<=n*m;k++){
					vec[i].push_back(in[k]);
				}
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				for(int k=0;k<=n*m;k++){
					vec[i].push_back(in[k]);
				}
			}
		}
	}
	
	for(int i=0;i<=vec.size()-1;i++){
		for(int j=0;j<=vec[i].size()-1;j++){
			if(vec[i][j]==index){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	} 
	return 0;
} 