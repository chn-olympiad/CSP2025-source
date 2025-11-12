#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int t,n,yi,er,san,sum=0;
	cin>>t;
	int xg[100000][3];
	int max[100000][3]={};
	for(int a=1;a<=t;a++){
		cin>>n;
		for(int b=0;b<n;b++){
			for(int c=0;c<3;c++){
				cin>>xg[b][c];
				sum=xg[b][c]+sum;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
} 
