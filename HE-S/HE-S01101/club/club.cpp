#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int w=0;w<t;w++){
		int n,b[3]={0};
		cin>>n;
		int d[n][3],xiao=0,da=0,e=n/2;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>d[i][j];
			}
		}
		for(int j=0;j<3;j++){
			if(b[j]<=e){
				for(int l=0;l<n;l++){
					xiao=d[l][j]+xiao;
				}
				b[j]++;
			}	
		da=max(da,xiao);
		}
		cout<<da;
	}
	return 0;
} 
