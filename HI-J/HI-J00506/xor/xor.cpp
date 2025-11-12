#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
int a[10009][2]={};
int yi=0,sum=0,j=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		if(a[i][0]==m){
			a[i][1]=1;
			sum++;
		}
	}	
	
	for(int i=1;i<=n;i++){
		if(a[i][1]==1){
			yi=0;
			continue;
		}
		for(j=i+1;j<=n;j++){
			if(a[j][1]==1){
				yi=0;
				break;
			}
			
			if(yi==m){
				for(int y=i;y<=j;y++){
					a[y][1]=1;
				}	
				yi=0;
				sum++;
				break;
			}
			else{
				yi+=a[j-1][0]^a[j][0];
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
