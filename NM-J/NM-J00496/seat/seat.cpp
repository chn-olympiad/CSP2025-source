#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long long n=0,m=0;
	cin>>n>>m;
	vector<int> vec;
	int r=0;
	for(long long i=0;i<n*m;i++){
		int t=0;
		cin>>t;
		if(i==0){
			r=t;
		}
		vec.push_back(t);
	}
//	for(long long i=0;i<n*m;i++){
//		cout<<vec[i]<<" ";
//	}

	for(int i=0;i<n*m;i++){
		for(int j=1;j<n*m-i;j++){
			if(vec[j-1]<vec[j]){
				int t=vec[j-1];
				vec[j-1]=vec[j];
				vec[j]=t;
			}
		}
	}
		
		
//	for(long long i=0;i<n*m;i++){
//		cout<<vec[i]<<" ";
//		}
//	cout<<"\n";
	int seat[15][15]={};
	int seati=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			
			for(int j=1;j<=n;j++){
				seat[i][j]=vec[seati];
				seati++;
//				cout<<i<<" "<<j<<"   ";
			}
			
		}else{
			for(int j=n;j>=1;j--){
				seat[i][j]=vec[seati];
				seati++;
//				cout<<i<<" "<<j<<"   ";
			}
		}
//		cout<<"\n";
	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==r){
				cout<<i<<" "<<j;
				
			}
		}
	}
	return 0;
}
