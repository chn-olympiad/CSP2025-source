#include<bits/stdc++.h> 
using namespace std;
const int N=500005;
long long b[N][N];
int n,k; 
void ww(int i , int j){
	for(;j<=j+i-1;j++){
		b[1][j]=-1;
	}
	return;
}
int ace(){
	for(int i=1;i<=n;i++)
	{
		if(b[1][i]!=-1)
			return 1;
	}
	return 0;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[1][i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(b[i][j]==k){
				ww(i,j);
				ans++;
			}
		}
		for(int j=1;j<=n-i;j++){
			if(b[i][j]!=-1&&b[i][j+1]!=-1)
				b[i+1][j]=(b[i][j]^b[i][j+1]);
		}
		if(ace()==0) 
			break;
	}
	cout<<ans;
	return 0;
}
