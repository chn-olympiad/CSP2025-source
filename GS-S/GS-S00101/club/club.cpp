#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int p=0;p<t;p++){
		int n,ans=0;
		cin>>n;
		vector<vector<int>>d(n,vector<int>(3));
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>d[i][j];
			}
		}
		if(n==2){
			ans=max(d[0][0]+d[1][1],max(d[0][0]+d[1][2],max(d[0][1]+d[1][0],max(d[0][1]+d[1][2],max(d[0][2]+d[1][0],d[0][2]+d[1][1])))));
			cout<<ans;
		}else{
			for(int i=0;i<n;i++){
				for(int j=0;j<n-1;j++){
					if(d[j][0]<=d[j+1][0]){
						int a;
						a=d[j][0];
						d[j][0]=d[j+1][0];
						d[j+1][0]=a;
					}
				}
			}
			for(int i=0;i<n/2;i++){
				ans+=d[i][0];
			}
			cout<<ans;
		}
		
	}
	return 0;
}
