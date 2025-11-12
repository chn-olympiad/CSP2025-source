#include<bits/stdc++.h>
using namespace std;
int n,m,j,r,maxn,a;
int s[101],k[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	r=s[1];
	for(int i=1;i<=m;i++){
		for(j=1;j>=1&&j<=n;){
			maxn=-1; 
			for(int o=1;o<=n*m;o++){
				if(maxn<s[o]){
				maxn=s[o]; 
				a=o;
				}
			}
			k[i][j]=maxn;
			s[a]=-1; 
			if(i%2==1)j++;
			else j--;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k[i][j]==r)cout<<i<<" "<<j; 
		} 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
