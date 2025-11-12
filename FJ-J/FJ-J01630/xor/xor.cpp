#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int N=5*100000+5;
int start_end[3][N];
long long a[N];
int main(){
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int yhsum=0,st=0,en=0,zubie=1;
	for(int i=1;i<=n;i++){
		yhsum=a[i];
		st=i;
		for(int j=i+1;j<=n;j++){
			if(yhsum==k){
				en=j-1;
				start_end[1][zubie]=st;
				start_end[2][zubie++]=en;
			}else{
				yhsum=yhsum^a[j];
			}
		}
	}
	for(int i=1;i<=zubie;i++){
		for(int j=i+1;j<=zubie;j++){
			if(start_end[1][j]==-1) continue;
			if(start_end[1][j]==start_end[1][j]){
				zubie--;
				start_end[1][j]=-1;
			}
		}
	}
	for(int i=1;i<=zubie;i++){
		for(int j=i+1;j<=zubie;j++){
			if(start_end[2][j]==-1) continue;
			if(start_end[2][j]==start_end[1][i]){
				zubie--;
				start_end[2][j]=-1;
			}
		}
	}
	cout<<zubie;
	return 0;
}

