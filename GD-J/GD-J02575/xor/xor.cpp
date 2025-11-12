#include<iostream>
using namespace std;
int n,k,r,cnt;
long long f[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f[i][i];
	}
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<j;i++){
			f[i][j]=f[i][j-1]^f[j][j];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			if(f[i][j]==k&&r<i){
				cnt++;
				r=j;
			}
		}
	}
	cout<<cnt;
}
