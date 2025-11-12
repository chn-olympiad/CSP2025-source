#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	long long a[n+100]={0},b[n+100][n+100]={0},c[5]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i];
			cin>>b[i][j];	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(b[i][j]>b[i][j+1]){
				c[j]++;
				if(c[j]>x/2){
					if(){
						
				    }
				}
			}
		}
	}
	return 0;
}
